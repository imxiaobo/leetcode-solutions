class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // n, idx
    unordered_map<int, int> m;
    int size = nums.size();
    for (int idx2 = 1; idx2 <= size; ++idx2) {
      int n = nums[idx2 - 1];
      auto found = m.find(target - n);
      if (found != m.end()) {
        int idx1 = found->second;
        if (idx1 < idx2) {
          return {idx1, idx2};
        }
      }
      m[n] = idx2;
    }
  }
};
