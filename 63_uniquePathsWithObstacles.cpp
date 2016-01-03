class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {

    int mm[100][100];
    int row = obstacleGrid.size();
    if (row == 0)
      return 0;
    int column = obstacleGrid[0].size();
    if (column == 0)
      return 0;
    // initialize
    for (int x = 0; x < row; ++x) {
      for (int y = 0; y < column; ++y) {
        mm[x][y] = -1;
      }
    }

    if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][column - 1] == 1)
      return 0;
    mm[0][0] = 1;

    return uniquePathsWithObstacles(obstacleGrid, row - 1, column - 1, mm);
  }

  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid, int m, int n,
                               int mm[100][100]) {

    if (mm[m][n] != -1)
      return mm[m][n];

    if (obstacleGrid[m][n] == 1) {
      mm[m][n] = 0;
    }

    else {
      int sum = 0;

      if (m > 0) {
        sum += uniquePathsWithObstacles(obstacleGrid, m - 1, n, mm);
      }
      if (n > 0) {
        sum += uniquePathsWithObstacles(obstacleGrid, m, n - 1, mm);
      }

      mm[m][n] = sum;
    }

    return mm[m][n];
  }
};
