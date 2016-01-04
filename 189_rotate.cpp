class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    if (nums.empty() || nums.size() == 1)
      return;
    reverse(nums.begin(), nums.begin() + nums.size() - k % nums.size());
    reverse(nums.begin() + nums.size() - k % nums.size(), nums.end());
    reverse(nums.begin(), nums.end());
  }
};
