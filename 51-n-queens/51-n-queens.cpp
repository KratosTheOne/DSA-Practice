class Solution {
public:
    
    void queenSolver(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, 
                     vector<int> &lowerDiag, vector<int> &upperDiag, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;
                queenSolver(col + 1, board, ans, leftRow, lowerDiag, upperDiag, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i = 0; i < n; i++)
            board[i] = s;
        
        vector<int> leftRow(n, 0), lowerDiag(2 * n - 1, 0), upperDiag(2 * n - 1, 0);
        
        queenSolver(0, board, ans, leftRow, lowerDiag, upperDiag, n);
        
        return ans;
    }
    
    /*
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
    */
};