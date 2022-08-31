//T.C & S.C -> O(n * m) & O(n * m)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int vis[n][m];
        
        queue<pair<pair<int, int>, int>> q;
        
        int cntFresh = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1)
                {
                    cntFresh++;
                }
            }
        }
        
        int tm = 0;
        int cnt = 0;
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int nrow = r + dx[i];
                int ncol = c + dy[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        
        if(cnt != cntFresh)
            return -1;
        
        return tm;
    }
};