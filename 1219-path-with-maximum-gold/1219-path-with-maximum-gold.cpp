// T.C & S.C -> O(m * n * 4^g) & O(g)
// BFS Solution
class Solution
{
public:
    int getMaximumGold(vector<vector<int>> &grid)
    {

        int rows = grid.size();
        int cols = grid[0].size();
        int totalGold = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                totalGold += grid[row][col];
            }
        }

        int maxGold = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] != 0)
                {
                    maxGold = max(maxGold, bfsBacktrack(grid, rows, cols, row, col));
                    if (maxGold == totalGold)
                        return totalGold;
                }
            }
        }
        return maxGold;
    }

private:
    const vector<int> DIRECTIONS = {0, 1, 0, -1, 0};

    int bfsBacktrack(vector<vector<int>> &grid, int rows, int cols, int row, int col)
    {
        queue<tuple<int, int, int, bitset<1024>>> queue;
        bitset<1024> visited;
        int maxGold = 0;
        visited[row * cols + col] = 1;
        queue.push({row, col, grid[row][col], visited});

        while (!queue.empty())
        {
            auto [currRow, currCol, currGold, currVis] = queue.front();
            queue.pop();
            maxGold = max(maxGold, currGold);

            for (int direction = 0; direction < 4; direction++)
            {
                int nextRow = currRow + DIRECTIONS[direction];
                int nextCol = currCol + DIRECTIONS[direction + 1];

                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && grid[nextRow][nextCol] != 0 && !currVis[nextRow * cols + nextCol])
                {
                    currVis[nextRow * cols + nextCol] = 1;
                    queue.push({nextRow, nextCol, currGold + grid[nextRow][nextCol], currVis});
                    currVis[nextRow * cols + nextCol] = 0;
                }
            }
        }
        return maxGold;
    }
};

/*
T.C & S.C -> O(m * n * 4^g) & O(g)
DFS Solution
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxGold = 0;

        //Search for the path with max gold
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                maxGold = max(maxGold, dfsBacktrack(grid, rows, cols, row, col));
            }
        }
        return maxGold;
    }

private:
    const vector<int> DIRECTIONS = {0, 1, 0, -1, 0};

    int dfsBacktrack(vector<vector<int>>& grid, int rows, int cols, int row, int col) {

        //Base case: when cell is not in the matrix or 0 gold
        if(row < 0 || col < 0 || row == rows || col == cols || grid[row][col] == 0) {
            return 0;
        }
        int maxGold = 0;

        //Mark the current cell visited and save the value
        int originalValue = grid[row][col];
        grid[row][col] = 0;

        //Backtrack in all 4 directions
        for(int direction = 0; direction < 4; direction++)
        {
            maxGold = max(maxGold, dfsBacktrack(grid, rows, cols, DIRECTIONS[direction] + row, DIRECTIONS[direction + 1] + col));
        }

        //Set the cell back to its original value
        grid[row][col] = originalValue;
        return maxGold + originalValue;
    }
};
*/