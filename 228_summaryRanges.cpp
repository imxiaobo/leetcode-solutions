class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {

    vector<string> results;
    int idx = 0;
    while (idx < nums.size()) {
      int e = idx;
      while (e < nums.size() - 1 && nums[e] + 1 == nums[e + 1])
        ++e;

      if (e > idx) {
        results.push_back(to_string(nums[idx]) + "->" + to_string(nums[e]));
        idx = e + 1;
      } else {
        results.push_back(to_string(nums[idx]));
        ++idx;
      }
    }

    return results;
  }
};
