class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {

    if (matrix.empty())
      return 0;

    vector<int> histogram(matrix[0].size(), 0);
    int area = 0;
    for (int row = 0; row < matrix.size(); ++row) {
      for (int column = 0; column < matrix[row].size(); ++column) {
        if (matrix[row][column] == '0') {
          histogram[column] = 0;
        } else {
          ++histogram[column];
        }
      }
      area = max(area, maxRectangleInHistogram(histogram));
    }
    return area;
  }

  int maxRectangleInHistogram(vector<int> &histogram) {
    int area = 0;
    stack<int> inc;

    histogram.push_back(0);
    for (int idx = 0; idx < histogram.size(); ++idx) {
      while (!inc.empty() && histogram[idx] < histogram[inc.top()]) {
        int height = histogram[inc.top()];
        inc.pop();
        int width = inc.empty() ? idx : idx - inc.top() - 1;
        area = max(area, height * width);
      }
      inc.push(idx);
    }
    histogram.pop_back();

    return area;
  }
};
