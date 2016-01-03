class Solution {
public:
  bool canJump(vector<int> &nums) {

    int reachable = 0;
    for (int idx = 0; idx < nums.size(); ++idx) {
      reachable = max(nums[idx] + idx, reachable);
      if (idx == reachable)
        break;
    }

    return reachable >= nums.size() - 1;
  }
};
