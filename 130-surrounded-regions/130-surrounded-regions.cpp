//T.C & S.C -> O(n * m * 4) & O(n * m)

class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& mat, vector<int>& dx, vector<int>& dy)
    {
        vis[r][c] = 1;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mat[nr][nc] == 'O')
            {
                dfs(nr, nc, vis, mat, dx, dy);
            }
        }
    }
public:
    void solve(vector<vector<char>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        //Traverse rows
        for(int j = 0; j < m; j++)
        {
            //First row
            if(!vis[0][j] && mat[0][j] == 'O')
                dfs(0, j, vis, mat, dx, dy);
                
            //Last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O')
                dfs(n-1, j, vis, mat, dx, dy);
        }
        
        //Traverse cols
        for(int i = 0; i < n; i++)
        {
            //First col
            if(!vis[i][0] && mat[i][0] == 'O')
                dfs(i, 0, vis, mat, dx, dy);
                
            //Last col
            if(!vis[i][m-1] && mat[i][m-1] == 'O')
                dfs(i, m-1, vis, mat, dx, dy);
        }
        
        //Convert in matrix
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }
    }
};