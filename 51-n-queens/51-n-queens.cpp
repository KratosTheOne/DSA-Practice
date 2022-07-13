class Solution {
public:
    
    bool isQueenSafe(int row, int col, vector<string> board, int n)
    {
        int tempRow = row;
        int tempCol = col;
        
        // upper left diagnol
        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        // left diagnol
        row = tempRow;
        col = tempCol;
        
        while(col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        // bottom left diagnol
        row = tempRow;
        col = tempCol;
        
        while(row < n && col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    void queenSolver(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(isQueenSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                queenSolver(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i = 0; i < n; i++)
            board[i] = s;
        
        queenSolver(0, board, ans, n);
        
        return ans;
    }
};