class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.empty())
      return 0;
    if (nums.size() == 1)
      return nums[0];
    return max(robn(nums, 0, nums.size() - 2), robn(nums, 1, nums.size() - 1));
  }

  int robn(vector<int> &nums, int b, int e) {
    int inclusive = 0, exclusive = 0;
    for (int i = b; i <= e; ++i) {
      int tmp = inclusive;
      inclusive = exclusive + nums[i];
      exclusive = max(tmp, exclusive);
    }
    return max(inclusive, exclusive);
  }
};
