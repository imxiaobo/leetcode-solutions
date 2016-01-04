class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {

    if (matrix.empty())
      return false;

    int row = matrix.size();
    int column = matrix[0].size();

    int x = row - 1, y = 0;
    while (x >= 0 && y < column) {
      if (matrix[x][y] == target)
        return true;
      else if (matrix[x][y] < target)
        ++y;
      else
        --x;
    }

    return false;
  }
};
