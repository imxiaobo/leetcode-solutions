class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {

    sort(nums.begin(), nums.end());

    vector<vector<int>> results = {{}};

    for (int n : nums) {
      int size = results.size();
      for (int i = 0; i < size; ++i) {
        vector<int> subset = results[i];
        subset.push_back(n);
        results.emplace_back(move(subset));
      }
    }

    return results;
  }
};
