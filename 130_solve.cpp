class Solution {
public:
  void solve(vector<vector<char>> &board) {
    if (board.empty())
      return;
    int R = board.size(), C = board[0].size();
    queue<pair<int, int>> s;

    // first/last row
    for (int column = 0; column < C; ++column) {
      if (board[0][column] == 'O') {
        board[0][column] = '!';
        s.emplace(0, column);
      }
      if (board[R - 1][column] == 'O') {
        board[R - 1][column] = '!';
        s.emplace(R - 1, column);
      }
    }

    // first/last column
    for (int row = 0; row < R; ++row) {
      if (board[row][0] == 'O') {
        board[row][0] = '!';
        s.emplace(row, 0);
      }
      if (board[row][C - 1] == 'O') {
        board[row][C - 1] = '!';
        s.emplace(row, C - 1);
      }
    }

    floodFill(board, s);

    // flip
    for (auto &row : board) {
      for (auto &cell : row) {
        if (cell == 'O') {
          cell = 'X';
        } else if (cell == '!') {
          cell = 'O';
        }
      }
    }
  }

  void floodFill(vector<vector<char>> &board, queue<pair<int, int>> &s) {
    while (!s.empty()) {

      auto c = s.front();
      int row = c.first;
      int column = c.second;
      s.pop();

      // left
      if (column - 1 >= 0 && board[row][column - 1] == 'O') {
        board[row][column - 1] = '!';
        s.emplace(row, column - 1);
      }
      // down
      if (row + 1 < board.size() && board[row + 1][column] == 'O') {
        board[row + 1][column] = '!';
        s.emplace(row + 1, column);
      }
      // right
      if (column + 1 < board[row].size() && board[row][column + 1] == 'O') {
        board[row][column + 1] = '!';
        s.emplace(row, column + 1);
      }
      // up
      if (row - 1 >= 0 && board[row - 1][column] == 'O') {
        board[row - 1][column] = '!';
        s.emplace(row - 1, column);
      }
    }
  }
};
