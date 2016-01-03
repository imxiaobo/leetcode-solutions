class Solution {
public:
  int uniquePaths(int m, int n) {
    int dp[100][100] = {0};
    return uniquePaths(m - 1, n - 1, dp);
  }

  int uniquePaths(int m, int n, int dp[100][100]) {
    if (dp[m][n] != 0)
      return dp[m][n];

    if (m == 0 || n == 0) {
      return 1;
    }

    int sum = 0;
    if (m > 0)
      sum += uniquePaths(m - 1, n, dp);
    if (n > 0)
      sum += uniquePaths(m, n - 1, dp);

    dp[m][n] = sum;
    return sum;
  }
};
