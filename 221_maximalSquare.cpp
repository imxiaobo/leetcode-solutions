class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {

    if (matrix.empty())
      return 0;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

    int result = 0;
    for (int row = 0; row < matrix.size(); ++row) {
      if (matrix[row][0] == '1') {
        dp[row][0] = 1;
        result = 1;
      }
    }
    for (int column = 1; column < matrix[0].size(); ++column) {
      if (matrix[0][column] == '1') {
        dp[0][column] = 1;
        result = 1;
      }
    }

    for (int row = 1; row < matrix.size(); ++row) {
      for (int column = 1; column < matrix[row].size(); ++column) {
        if (matrix[row][column] == '1') {
          dp[row][column] =
              1 + min(dp[row - 1][column - 1],
                      min(dp[row - 1][column], dp[row][column - 1]));
          result = max(result, dp[row][column] * dp[row][column]);
        }
      }
    }
    return result;
  }
};
