class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {

    if (grid.empty())
      return 0;

    vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
    return minPathSum(grid, 0, 0, memo);
  }

  int minPathSum(vector<vector<int>> &grid, int row, int column,
                 vector<vector<int>> &memo) {
    if (memo[row][column] != -1)
      return memo[row][column];

    if (row == grid.size() - 1 && column == grid[row].size() - 1) {
      return memo[row][column] = grid[row][column];
    }

    int minRight = INT_MAX, minDown = INT_MAX;

    if (row + 1 < grid.size()) {
      minRight = minPathSum(grid, row + 1, column, memo);
    }
    if (column + 1 < grid[row].size()) {
      minDown = minPathSum(grid, row, column + 1, memo);
    }

    return memo[row][column] = grid[row][column] + min(minRight, minDown);
  }
};
