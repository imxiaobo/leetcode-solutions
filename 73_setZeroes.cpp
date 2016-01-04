class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {

    if (matrix.empty())
      return;

    bool column0 = false;
    int rows = matrix.size(), columns = matrix[0].size();

    for (int r = 0; r < rows; ++r) {
      if (matrix[r][0] == 0)
        column0 = true;

      for (int c = 1; c < columns; ++c) {
        if (matrix[r][c] == 0)
          matrix[r][0] = matrix[0][c] = 0;
      }
    }

    for (int r = rows - 1; r >= 0; --r) {
      for (int c = columns - 1; c > 0; --c) {
        if (matrix[r][0] == 0 || matrix[0][c] == 0)
          matrix[r][c] = 0;
      }

      if (column0)
        matrix[r][0] = 0;
    }
  }
};
