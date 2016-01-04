class Solution {
public:
  int minSubArrayLen(int s, vector<int> &nums) {
    int left = 0, right = 0, sum = 0, result = INT_MAX;
    while (right <= nums.size()) {
      if (sum < s) {
        if (right < nums.size()) {
          sum += nums[right];
          ++right;
        } else {
          break;
        }
      } else {
        result = min(result, right - left);
        sum -= nums[left];
        ++left;
      }
    }
    return result == INT_MAX ? 0 : result;
  }
};
