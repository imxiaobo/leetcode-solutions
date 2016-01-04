class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> map;

    for (int idx = 0; idx < nums.size(); ++idx) {
      if (map.find(nums[idx]) != map.end() && idx - map[nums[idx]] <= k)
        return true;
      // update or insert new idx
      map[nums[idx]] = idx;
    }

    return false;
  }
};
