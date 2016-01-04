class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {

    vector<vector<int>> subsets{{}};

    sort(nums.begin(), nums.end());

    for (int idx = 0, lastPos = 0; idx < nums.size(); ++idx) {
      int to = subsets.size();

      for (int from = (idx != 0 && nums[idx] == nums[idx - 1]) ? lastPos : 0;
           from < to; ++from) {
        auto subset = subsets[from];
        subset.push_back(nums[idx]);
        subsets.emplace_back(move(subset));
      }

      lastPos = to;
    }

    return subsets;
  }
};
