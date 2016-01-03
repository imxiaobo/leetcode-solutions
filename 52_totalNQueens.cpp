class Solution {
public:
  int totalNQueens(int n) {
    int result = 0;
    vector<vector<int>> state(n, vector<int>(n, 0));
    dfs(state, n, 0, result);
    return result;
  }

  void dfs(vector<vector<int>> &state, int n, int queens, int &result) {
    if (queens == n) {
      ++result;
    } else {
      int column = queens;
      for (int row = 0; row < state.size(); ++row) {

        if (state[row][column] == 0) {
          flipState(state, row, column, n, true);
          dfs(state, n, queens + 1, result);
          flipState(state, row, column, n, false);
        }
      }
    }
  }

  void flipState(vector<vector<int>> &state, int row, int column, int n,
                 bool flag) {
    int op = flag ? 1 : -1;

    state[row][column] = flag ? 1 : 0;

    for (int r = 0; r < n; ++r) {
      if (r != row)
        state[r][column] += op;
    }
    for (int c = 0; c < n; ++c) {
      if (c != column)
        state[row][c] += op;
    }

    int x = row - 1, y = column - 1;
    while (x >= 0 && y >= 0) {
      state[x][y] += op;
      --x;
      --y;
    }

    x = row + 1;
    y = column + 1;
    while (x < n && y < n) {
      state[x][y] += op;
      ++x;
      ++y;
    }

    x = row - 1, y = column + 1;
    while (x >= 0 && y < n) {
      state[x][y] += op;
      --x;
      ++y;
    }

    x = row + 1;
    y = column - 1;
    while (x < n && y >= 0) {
      state[x][y] += op;
      ++x;
      --y;
    }
  }
};
