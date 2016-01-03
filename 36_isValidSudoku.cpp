class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {

    for (int row = 0; row < board.size(); ++row) {
      vector<bool> s(10, false);
      for (int column = 0; column < board[row].size(); ++column) {
        if (board[row][column] != '.') {
          if (s[board[row][column]])
            return false;
          else
            s[board[row][column]] = true;
        }
      }
    }

    for (int column = 0; column < board[0].size(); ++column) {
      vector<bool> s(10, false);
      for (int row = 0; row < board.size(); ++row) {
        if (board[row][column] != '.') {
          if (s[board[row][column]])
            return false;
          else
            s[board[row][column]] = true;
        }
      }
    }

    for (int r = 0; r < board.size(); r += 3) {
      for (int c = 0; c < board[r].size(); c += 3) {
        vector<bool> s(10, false);
        for (int row = r; row < r + 3; ++row) {
          for (int column = c; column < c + 3; ++column) {
            if (board[row][column] != '.') {
              if (s[board[row][column]])
                return false;
              else
                s[board[row][column]] = true;
            }
          }
        }
      }
    }

    return true;
  }
};
