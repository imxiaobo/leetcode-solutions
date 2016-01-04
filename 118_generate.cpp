class Solution {
public:
  vector<vector<int>> generate(int numRows) {

    vector<vector<int>> t(numRows);

    for (int row = 0; row < numRows; ++row) {
      for (int column = 0; column <= row; ++column) {
        if (column == row || column == 0) {
          t[row].push_back(1);
        } else {
          t[row].push_back(t[row - 1][column] + t[row - 1][column - 1]);
        }
      }
    }

    return move(t);
  }
};
