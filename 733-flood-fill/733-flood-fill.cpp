//T.C & S.C -> O(n*m*4) & O(n*m)

class Solution {
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
private:

    void dfs(int r, int c, vector<vector<int>>& image, vector<vector<int>>& ans, int iniColor, int newColor)
    {
        ans[r][c] = newColor;

        int n = image.size(), m = image[0].size();

        for(int i = 0; i < 4; i++)
        {
            int nrow = r + dx[i];
            int ncol = c + dy[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
               && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
            {
                dfs(nrow, ncol, image, ans, iniColor, newColor);
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int iniColor = image[sr][sc];

        vector<vector<int>> ans = image;

        dfs(sr, sc, image, ans, iniColor, color);

        return ans;
    }
};