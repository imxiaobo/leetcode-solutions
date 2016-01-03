class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {

    int n = matrix.size();

    for (int row = 0; row < n - 1; ++row) {
      for (int column = 0; column + row < n - 1; ++column) {
        swap(matrix[row][column], matrix[n - column - 1][n - row - 1]);
      }
    }

    reverse(matrix.begin(), matrix.end());
  }
};
