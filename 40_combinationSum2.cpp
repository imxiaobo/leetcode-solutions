class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    auto pivot = partition(candidates.begin(), candidates.end(),
                           [target](int x) { return x <= target; });
    candidates.erase(pivot, candidates.end());
    sort(candidates.begin(), candidates.end());

    vector<int> combination;
    vector<vector<int>> combinations;

    combinationSum(target, candidates, 0, combination, combinations);
    return combinations;
  }

  void combinationSum(int target, vector<int> &candidates, int start,
                      vector<int> &combination,
                      vector<vector<int>> &combinations) {
    if (target == 0) {
      if (!combination.empty()) {
        combinations.emplace_back(combination);
      }
    } else {
      for (int idx = start; idx < candidates.size(); ++idx) {
        if (target - candidates[idx] < 0)
          break;
        combination.push_back(candidates[idx]);
        combinationSum(target - candidates[idx], candidates, idx + 1,
                       combination, combinations);
        combination.pop_back();
        // skip duplications
        while (idx + 1 < candidates.size() &&
               candidates[idx] == candidates[idx + 1])
          ++idx;
      }
    }
  }
};
