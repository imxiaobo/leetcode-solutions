class Solution {
public:
  void sortColors(vector<int> &nums) {

    int colorCount[3] = {0, 0, 0};
    for (int color : nums)
      ++colorCount[color];

    int k = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < colorCount[i]; ++j) {
        nums[k++] = i;
      }
    }
  }
};
