class NumMatrix {
  vector<vector<int>> regionSum;

public:
  NumMatrix(vector<vector<int>> &matrix) {

    if (matrix.empty())
      return;

    regionSum.resize(matrix.size(), vector<int>(matrix[0].size(), 0));

    regionSum[0][0] = matrix[0][0];

    for (int row = 1; row < matrix.size(); ++row) {
      regionSum[row][0] = regionSum[row - 1][0] + matrix[row][0];
    }
    for (int column = 1; column < matrix[0].size(); ++column) {
      regionSum[0][column] = regionSum[0][column - 1] + matrix[0][column];
    }
    for (int row = 1; row < matrix.size(); ++row) {
      for (int column = 1; column < matrix[row].size(); ++column) {
        regionSum[row][column] =
            regionSum[row - 1][column] + regionSum[row][column - 1] -
            regionSum[row - 1][column - 1] + matrix[row][column];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {

    int sum = 0;

    if (row2 >= 0 && col2 >= 0)
      sum += regionSum[row2][col2];
    if (row1 >= 1 && col2 >= 0)
      sum -= regionSum[row1 - 1][col2];
    if (row2 >= 0 && col1 >= 1)
      sum -= regionSum[row2][col1 - 1];
    if (row1 >= 1 && col1 >= 1)
      sum += regionSum[row1 - 1][col1 - 1];

    return sum;
  }
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
