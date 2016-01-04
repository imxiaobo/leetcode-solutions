class Solution {
public:
  /*
      int lengthOfLIS(vector<int>& nums) {

          if (nums.empty()) return 0;
          vector<int> memo(nums.size(), 1);

          int result = 1;
          for (int i = 0; i < nums.size(); ++i)
          {
              for (int j = 0; j < i; ++j)
              {
                  if (nums[i] > nums[j]) memo[i] = max(memo[j] + 1, memo[i]);
              }
              result = max(result, memo[i]);
          }
          return result;
      }
  */
  int lengthOfLIS(vector<int> &nums) {
    vector<int> tail;
    for (auto n : nums) {
      auto it = lower_bound(tail.begin(), tail.end(), n);
      if (it == tail.end())
        tail.push_back(n);
      else
        *it = n;
    }
    return tail.size();
  }
};
