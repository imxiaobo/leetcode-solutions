class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {

    vector<int> result;

    if (matrix.empty())
      return result;

    int rowBegin = 0, rowEnd = matrix.size() - 1, columnBegin = 0,
        columnEnd = matrix[0].size() - 1;

    while (rowBegin <= rowEnd && columnBegin <= columnEnd) {
      // right;
      for (int c = columnBegin; c <= columnEnd; ++c) {
        result.push_back(matrix[rowBegin][c]);
      }
      ++rowBegin;

      // down;
      for (int r = rowBegin; r <= rowEnd; ++r) {
        result.push_back(matrix[r][columnEnd]);
      }
      --columnEnd;

      // left;
      if (rowBegin > rowEnd)
        break;
      for (int c = columnEnd; c >= columnBegin; --c) {
        result.push_back(matrix[rowEnd][c]);
      }
      --rowEnd;

      // up;
      if (columnBegin > columnEnd)
        break;
      for (int r = rowEnd; r >= rowBegin; --r) {
        result.push_back(matrix[r][columnBegin]);
      }
      ++columnBegin;
    }

    return result;
  }
};
