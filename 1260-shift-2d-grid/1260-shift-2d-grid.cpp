class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        k = k % (n * m);
        int counter = 0;
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int index = m * i + j;
                
                int shiftedPosition = (index + k)%(m*n);
                
                int row = (shiftedPosition/m);
                int col = (shiftedPosition % m);
                ans[row][col] = grid[i][j];
            }
        }
        return ans;
    }
};