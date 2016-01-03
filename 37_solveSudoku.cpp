class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) {
    // assume board is valid
    solve(board, 0, 0);
  }

  bool solve(vector<vector<char>> &board, int rowBegin, int columnBegin) {
    // resume from last row
    for (int row = rowBegin; row < board.size(); ++row) {
      // resume from last column
      for (int column = columnBegin; column < board[row].size(); ++column) {
        // fill in next cell
        if (board[row][column] == '.') {
          for (char digit = '1'; digit <= '9'; ++digit) {
            // pruning
            if (isValid(board, row, column, digit)) {
              // backtracking
              board[row][column] = digit;
              // early exit
              if (solve(board, row, column))
                return true;
              // recover
              board[row][column] = '.';
            }
          }
          // all possible atempts failed
          return false;
        }
      }
      // reset columnBegin since we'll go to next row
      columnBegin = 0;
    }
    // yeah, we get it
    return true;
  }

  bool isValid(vector<vector<char>> &board, int row, int column, char digit) {
    // check row
    for (int r = 0; r < board.size(); ++r) {
      if (board[r][column] == digit)
        return false;
    }
    // check column
    for (int c = 0; c < board[row].size(); ++c) {
      if (board[row][c] == digit)
        return false;
    }
    // check sub-matrix
    row = row / 3 * 3;
    column = column / 3 * 3;

    for (int r = row; r < row + 3; ++r) {
      for (int c = column; c < column + 3; ++c) {
        if (board[r][c] == digit)
          return false;
      }
    }

    return true;
  }
};
