```
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 15
0 <= grid[i][j] <= 100
There are at most 25 cells containing gold.


Editorial

Approach 1: Depth-First Search with Backtracking
Intuition
We need to collect the maximum amount of gold possible from a given grid.

It's possible to traverse the grid and find the cells containing gold using nested loops, but this won't provide us with the path with the maximum gold. Instead, we will use depth-first search (DFS) to search for the best path.

We can begin searching for gold in any cell of the grid that has gold, so we perform a depth-first search for gold starting at each cell.

Let's consider our search function. If the starting cell contains gold, we should continue searching for gold in the adjacent cells. However, if the starting cell does not contain gold, we should halt the search since this path cannot lead to a valid solution.

What if a cell in the middle of the search process doesn't contain gold? We could restart the entire search process, or we could backtrack to the last cell on this path that contained gold and resume the search from there.

This idea is called backtracking. If a certain choice cannot lead to a valid solution, we can implement backtracking to abandon the current choice to return to the last valid choice and explore other possibilities.

If you are not familiar with backtracking, we recommend you read our Backtracking Explore Card.

We will define a recursive function, dfsBacktrack, that returns the path with the maximum gold for a given starting cell.

Our base case occurs when the current cell contains no gold or when the given coordinates are outside the matrix boundary. In either case, we return zero.

Next, let's discuss the recursive case. First, we collect the gold at the current cell by saving its original value and setting the cell to 0.

Then, we explore the possible paths from this cell by calling dfsBacktrack recursively for each of the four adjacent cells and updating the maximum gold if we find a better path.

For a given cell with coordinates (row, col) the four neighbors are:

Below Neighbor: (row + 0, col + 1)
Right Neighbor: (row + 1, col + 0)
Above Neighbor: (row + 0, col - 1)
Left Neighbor: (row - 1, col + 0)
We can observe that we change the first neighbor's column by the same amount as the next neighbor's row. By extracting this pattern, we can store it in an array DIRECTIONS = {0, 1, 0, -1, 0}. For each neighbor cell i, the row will change by DIRECTIONS[i], and the column will change by DIRECTIONS[i + 1].

After the recursive calls, we reset the current cell to its original value. This allows us to backtrack and explore other potential paths from this cell.

We return the sum of the maximum gold obtained and the current cell's gold value, representing the total gold collected on the path up to this point.

Then, from the getMaximumGold function, we use nested loops to traverse the possible starting cells. For each cell, we call the dfsBacktrack function and update the maximum gold value each time we find a better path.

Algorithm
Initialize a constant array DIRECTIONS to {0, 1, 0, -1, 0}.
Initialize the variable rows to the number of rows in the grid and cols to the number of columns.
Initialize a variable maxGold for storing the amount of gold collected on any path so far to 0.
Define a function dfsBacktrack that finds the path with the maximum gold using DFS and backtracking. The function takes parameters grid, rows, cols, row, and col, representing the coordinates of the current cell within the grid.
Base Case: We cannot collect gold in the cell (row, col). If grid[row][col] equals 0, or if the cell is outside the grid, return zero. We check whether the cell is outside the grid using the condition row < 0 or col < 0 or row == rows or col == cols.
Initialize a local variable maxGold to 0.
Mark the current cell as visited and save the value. Initialize a variable originalVal to grid[row][col], and set grid[row][col] to 0.
Search each of the four adjacent cells. Call dfsBacktrack for the cells to the left, right, above, and below the current cell. Update the maximum gold if a better path is found.
Reset the current cell back to its original value so that when we backtrack, we can explore other possible paths from this cell.
Return the sum of maxGold and originalVal, which represents the gold collected on this path so far.
Using nested for loops for each cell (row, col) in the grid, find the maximum gold that can be collected starting at that cell using the dfsBacktrack function and update maxGold whenever a better path is found.
Return maxGold.

Complexity Analysis
Let nnn be the number of rows in the grid, mmm be the number of columns, and ggg be the number of gold cells.

Approach 2: Breadth-First Search with Backtracking
Intuition
When a problem can be solved with depth-first search, it can often also be solved with breadth-first search (BFS).

We will create a function, bfsBacktrack, that uses a breadth-first search to find the path with the maximum gold for a given starting cell.

We will use a queue to store the cells we need to search. Each entry in the queue contains the coordinates of the current cell, the gold found so far on the path, and a set storing the cells visited on this path so far.

When we pop the front cell from the queue, we store the amount of gold found on the path so far as currGold, and update the maxGold if the currGold is higher.

Then, if each of the four adjacent cells has gold, is inside the matrix, and has not yet been visited, we mark them as visited and add them to the queue with the updated gold collected. After adding the cell to the queue, we remove it from the visited set to explore other possible paths from this cell during backtracking.

To improve the efficiency of the solution, we calculate the total amount of gold in the matrix before searching. This way, if we discover a path that has the maximum possible total gold, we can halt the search process.

Similar to the above solution, we call bfsBacktrack for every starting cell in the matrix.

Algorithm
Initialize a constant array DIRECTIONS to {0, 1, 0, -1, 0}.
Initialize the variable rows to the number of rows in the grid and cols to the number of columns.
Calculate the total amount of gold in the grid using a running sum. Using nested for loops for each cell (row, col) in the grid, add the gold to totalGold.
Initialize a variable maxGold to store the amount of gold collected on the path with the maximum gold to 0.
Define a function bfsBacktrack that searches for the path with the maximum gold using BFS and backtracking. The parameters are the grid, rows, cols, row, and col, representing the current cell coordinates in the grid.
Initialize a queue queue which stores the path and gold collected for a given cell.
Initialize a set visited for storing (row, col) pairs we have already visited.
Initialize a local variable maxGold to 0.
Add the starting (row, col) pair to the visited set.
Add the starting cell's row, col, amount of gold, and visited set to the queue.
While the queue is not empty:
Pop the front entry from the queue. Save the row as currRow, the column as currCol, the visited set as currVis, and the gold as currGold.
Update maxGold to currGold if currGold is larger.
Search each of the four adjacent cells. For the cells to the left, right, above, and below of the current cell:
Set nextRow to the neighbor cell's row coordinates and nextCol to the neighbor's column coordinates.
Add the neighbor cell to the queue if it contains gold, is in the matrix, and has not been visited:
Mark this cell as visited in currVis.
Add this cell's gold to currGold and add the cell to the queue with a copy of the currVis set.
Remove this cell from currVis so that when we backtrack, we can explore other possible paths.
Return maxGold.
Using nested for loops for each cell (row, col) in the grid, find the maximum gold that can be collected at that cell using the bfsBacktrack function and update maxGold when a better path is found. If a path with the totalGold is found, return the totalGold.
Return maxGold.
```
