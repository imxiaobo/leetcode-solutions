class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {

    if (n == 0)
      return {};

    vector<vector<int>> matrix(n, vector<int>(n));

    int rowBegin = 0, rowEnd = n - 1, columnBegin = 0, columnEnd = n - 1;

    int x = 0;

    while (rowBegin <= rowEnd && columnBegin <= columnEnd) {
      // right;
      for (int c = columnBegin; c <= columnEnd; ++c) {
        matrix[rowBegin][c] = ++x;
      }
      ++rowBegin;

      // down;
      for (int r = rowBegin; r <= rowEnd; ++r) {
        matrix[r][columnEnd] = ++x;
      }
      --columnEnd;

      // left;
      if (rowBegin > rowEnd)
        break;
      for (int c = columnEnd; c >= columnBegin; --c) {
        matrix[rowEnd][c] = ++x;
      }
      --rowEnd;

      // up;
      if (columnBegin > columnEnd)
        break;
      for (int r = rowEnd; r >= rowBegin; --r) {
        matrix[r][columnBegin] = ++x;
      }
      ++columnBegin;
    }

    return move(matrix);
  }
};
