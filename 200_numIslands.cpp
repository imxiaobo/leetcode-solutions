class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty())
      return 0;
    int count = 0, R = grid.size(), C = grid[0].size();
    for (int row = 0; row < R; ++row) {
      for (int column = 0; column < C; ++column) {
        if (grid[row][column] == '1') {
          unionFind(grid, row, column, R, C);
          ++count;
        }
      }
    }
    return count;
  }

  bool unionFind(vector<vector<char>> &grid, int row, int column, int R,
                 int C) {
    // union find
    queue<pair<int, int>> q;
    grid[row][column] = '!';
    q.emplace(row, column);

    while (!q.empty()) {
      const auto &c = q.front();
      int row = c.first;
      int column = c.second;
      q.pop();
      // left
      if (column - 1 >= 0 && grid[row][column - 1] == '1') {
        grid[row][column - 1] = '!';
        q.emplace(row, column - 1);
      }
      // down
      if (row + 1 < R && grid[row + 1][column] == '1') {
        grid[row + 1][column] = '!';
        q.emplace(row + 1, column);
      }
      // right
      if (column + 1 < C && grid[row][column + 1] == '1') {
        grid[row][column + 1] = '!';
        q.emplace(row, column + 1);
      }
      // up
      if (row - 1 >= 0 && grid[row - 1][column] == '1') {
        grid[row - 1][column] = '!';
        q.emplace(row - 1, column);
      }
    }
  }
};
