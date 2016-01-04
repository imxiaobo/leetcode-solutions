class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {

    int row = lower_bound_columnwise(matrix, 0, matrix.size() - 1, 0, target);

    if (matrix[row][0] == target)
      return true;

    if (matrix[row][0] > target) {
      row = row - 1;
      if (row < 0)
        return false;
    }

    auto it = lower_bound(matrix[row].begin(), matrix[row].end(), target);
    if (it != matrix[row].end() && *it == target)
      return true;
    return false;
  }

  int lower_bound_columnwise(vector<vector<int>> &matrix, int first, int last,
                             int column, int target) {

    while (first < last) {
      int mid = (first + last) / 2;
      if (matrix[mid][column] == target)
        return mid;
      if (matrix[mid][column] > target) {
        last = mid - 1;
      } else {
        first = mid + 1;
      }
    }

    return first;
  }
};
