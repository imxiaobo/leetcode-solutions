class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<int>> state(n, vector<int>(n, 0));
    vector<vector<string>> result;
    dfs(board, state, result, n, 0);
    return result;
  }

  void dfs(vector<string> &board, vector<vector<int>> &state,
           vector<vector<string>> &result, int n, int row) {
    if (row == n) {
      result.emplace_back(board);
    } else {
      for (int column = 0; column < state[0].size(); ++column) {

        if (state[row][column] == 0) {
          addQueen(board, state, row, column, n);
          dfs(board, state, result, n, row + 1);
          removeQueen(board, state, row, column, n);
        }
      }
    }
  }

  void addQueen(vector<string> &board, vector<vector<int>> &state, int row,
                int column, int n) {
    board[row][column] = 'Q';
    flipState(state, row, column, n, true);
  }

  void removeQueen(vector<string> &board, vector<vector<int>> &state, int row,
                   int column, int n) {
    board[row][column] = '.';
    flipState(state, row, column, n, false);
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
