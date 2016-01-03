class Solution {
public:
  int trap(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int leftHighest = 0, rightHighest = 0;
    int water = 0;
    while (left < right) {
      if (height[left] < height[right]) {
        if (leftHighest < height[left]) {
          leftHighest = height[left];
        } else {
          water += leftHighest - height[left];
        }
        ++left;
      } else {
        if (rightHighest < height[right]) {
          rightHighest = height[right];
        } else {
          water += rightHighest - height[right];
        }
        --right;
      }
    }
    return water;
  }
};
