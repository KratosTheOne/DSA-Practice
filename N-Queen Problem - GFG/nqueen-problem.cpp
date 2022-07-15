// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
 void solve(vector<string>&board,int col,vector<int>&lower_diagonal,vector<int>&upper_diagonal,vector<int>&left,vector<int>&fill,vector<vector<int>>&ans,int n)
    {
        
        if(col==n)
        {
            ans.push_back(fill);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(left[row]==0 && lower_diagonal[row+col]==0 && upper_diagonal[n-1+col-row]==0)
            {
                left[row]=1;
                lower_diagonal[row+col]=1;
                upper_diagonal[n-1+col-row]=1;
                fill[row]=col+1;
                board[row][col]='Q';
                solve(board,col+1,lower_diagonal,upper_diagonal,left,fill,ans,n);
                left[row]=0;
                lower_diagonal[row+col]=0;
                upper_diagonal[n-1+col-row]=0;
                fill[row]=0;
                board[row][col]='.';
            }
        }
        
    }
    vector<vector<int>> nQueen(int n) {
        
        vector<string>board(n,string(n,'.'));
        vector<int>left(n,0);
        vector<int>upper_diagonal(2*n-1,0);
        vector<int>lower_diagonal(2*n-1,0);
        vector<vector<int>>ans;
        vector<int>fill(n,0);
        solve(board,0,lower_diagonal,upper_diagonal,left,fill,ans,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends