class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        // dir contains all 8  directions of traversal
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                int cnt=0; //for every place we count number of neighbouring ones
                for(vector<int> &d:dir){
                    int x=i+d[0];
                    int y=j+d[1];
                    if(x>=0 && y>=0 && x<n && y<m && board[x][y]%10==1) cnt++;
                    // conditions to ensure (x,y) are in bound.
                    //board[x][y]%10==1 to check the value in ones position as 
                    //overall value may have changed but ones position will 
                    //always have the intial value.
                }
                board[i][j]+=10*cnt; // Place count of neighbouring ones at tens position
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]==21 || board[i][j]/10==3) board[i][j]=1;
                // If cell was alive and remaining ones are two or remainig ones
                //are exactly three irrespective of cells initial state
                else board[i][j]=0;
    }
};