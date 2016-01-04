class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {

    // precondition check
    if (board.empty())
      return false;
    if (board[0].empty())
      return false;
    if (word.empty())
      return true;

    for (int row = 0; row < board.size(); ++row) {
      for (int column = 0; column < board[row].size(); ++column) {
        if (dfs(board, row, column, word, 0))
          return true;
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>> &board, int row, int column, string &word,
           int start) {
    // match all
    if (start >= word.size())
      return true;

    // not match
    if (row < 0 || row >= board.size() || column < 0 ||
        column >= board[row].size() || word[start] != board[row][column]) {
      return false;
    }

    // backtracking
    int bt = board[row][column];

    board[row][column] = '.';

    // dfs
    bool result = dfs(board, row - 1, column, word, start + 1) ||
                  dfs(board, row + 1, column, word, start + 1) ||
                  dfs(board, row, column - 1, word, start + 1) ||
                  dfs(board, row, column + 1, word, start + 1);

    // recover
    board[row][column] = bt;

    return result;
  }
};
