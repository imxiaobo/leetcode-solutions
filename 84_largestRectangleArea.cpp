class Solution {
public:
  int largestRectangleArea(vector<int> &height) {

    stack<int> stack;
    height.push_back(0);

    int area = 0;
    for (int idx = 0; idx < height.size(); ++idx) {
      while (!stack.empty() && height[idx] < height[stack.top()]) {
        int h = height[stack.top()];
        stack.pop();
        int w = stack.empty() ? idx : idx - stack.top() - 1;
        area = max(area, h * w);
      }
      stack.push(idx);
    }
    height.pop_back();
    return area;
  }
};
