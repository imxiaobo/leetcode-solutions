class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {

    int ROW = board.size(), COLUMN = (ROW == 0 ? 0 : board[0].size());

    for (int row = 0; row < ROW; ++row) {
      for (int column = 0; column < COLUMN; ++column) {
        int neighbors = 0;

        for (int r = max(0, row - 1); r < min(ROW, row + 2); ++r) {
          for (int c = max(0, column - 1); c < min(COLUMN, column + 2); ++c) {
            if (!(r == row && c == column))
              neighbors += board[r][c] % 2;
          }
        }

        if (board[row][column] % 2 == 1) {
          if (!(neighbors == 2 || neighbors == 3))
            board[row][column] = 3;
        } else {
          if (neighbors == 3)
            board[row][column] = 2;
        }
      }
    }

    for (int row = 0; row < ROW; ++row) {
      for (int column = 0; column < COLUMN; ++column) {
        if (board[row][column] == 3)
          board[row][column] = 0;
        if (board[row][column] == 2)
          board[row][column] = 1;
      }
    }
  }
};
