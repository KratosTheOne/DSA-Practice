//T.C && S.C -> O(m * n)

class Solution {
private:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<int>>& ocean)
    {
        int n = heights.size(), m = heights[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m) return;
        if(heights[i][j] < prev || ocean[i][j]) return;
        
        ocean[i][j] = 1;
        
        for(int d = 0; d < 4; d++)
        {
            int nr = i + dx[d];
            int nc = j + dy[d];
            
            dfs(heights, nr, nc, heights[i][j], ocean);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int r = heights.size(), c = heights[0].size();
        vector<vector<int>> res;
        
        vector<vector<int>> pacific(r, vector<int>(c, 0));
        vector<vector<int>> atlantic(r, vector<int>(c, 0));
        
        //DFS
        for(int i = 0; i < c; i++)
        {
            dfs(heights, 0, i, INT_MIN, pacific);
            dfs(heights, r - 1, i, INT_MIN, atlantic);
        }
        for(int i = 0; i < r; i++)
        {
            dfs(heights, i, 0, INT_MIN, pacific);
            dfs(heights, i, c - 1, INT_MIN, atlantic);
        }
        
        //Preparing result
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
};