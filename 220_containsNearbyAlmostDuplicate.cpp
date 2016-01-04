class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {

    multiset<long> bst;
    for (int idx = 0, size = nums.size(); idx < size; ++idx) {
      if (idx - k >= 1)
        bst.erase(bst.find(nums[idx - k - 1]));

      // auto it = bst.lower_bound(nums[idx] - t);
      // if (it != bst.end() && *it <= nums[idx] + t) return true;
      // bst.insert(nums[idx]);

      auto it = bst.insert(nums[idx]);

      auto next = it;
      if (++next != bst.end()) {
        if (*next - nums[idx] <= t)
          return true;
      }
      if (it != bst.begin()) {
        auto prev = it;
        if (nums[idx] - *(--prev) <= t)
          return true;
      }
    }

    return false;
  }
};
