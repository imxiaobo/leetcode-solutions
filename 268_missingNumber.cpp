class Solution {
public:
  int missingNumber(vector<int> &nums) {

    int sum = 0, n = nums.size();
    for (int x = 0; x < n; ++x) {
      sum += nums[x];
    }

    int allSum = (0 + n) * (n + 1) / 2;

    return allSum - sum;
  }
};
