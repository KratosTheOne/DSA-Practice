//T.C & S.C -> O(n^2 * Num of Neigbours) & O(n^2)

class Solution {
private:
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(int r, int c, int n, int m, vector<vector<char>>& grid)
    {
        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '0')
            return;
        
        grid[r][c] = '0';
        
        for(int i = 0; i < 4; i++)
        {
            int nrow = r + dx[i];
            int ncol = c + dy[i];
            
            dfs(nrow, ncol, n, m, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt = 0;
        
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(grid[r][c] == '1')
                {
                    cnt++;
                    dfs(r, c, n, m, grid);
                }
            }
        }
        
        return cnt;
    }
};