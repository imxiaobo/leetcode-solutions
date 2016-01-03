class Solution {
public:
  int maxSubArray(vector<int> &nums) {

    int sum = nums[0], smax = nums[0], smin = 0;

    for (int x = 1; x < nums.size(); ++x) {
      smin = min(smin, sum);
      sum += nums[x];
      smax = max(smax, sum - smin);
    }

    return smax;
  }
};
