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
    
    int countQueens(int col, vector<string> &board, int n)
    {
        if(col == n)
            return 1;
        
        int count = 0;
        
        for(int row = 0; row < n; row++)
        {
            if(isQueenSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                count += countQueens(col + 1, board, n);
                board[row][col] = '.';
            }
        }
        return count;
    } 
    
    int totalNQueens(int n) {
        
        vector<string> board(n);
        string s(n, '.');
        
        for(int i = 0; i < n; i++)
            board[i] = s;
        
        return countQueens(0, board, n);
    }
};