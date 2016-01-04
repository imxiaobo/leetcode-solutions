class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> path;
    vector<vector<int>> result;
    combinationSum3(k, n, 0, path, result);
    return move(result);
  }

  void combinationSum3(const int k, const int n, int pathSum, vector<int> &path,
                       vector<vector<int>> &result) {
    if (path.size() == k && pathSum == n) {
      result.emplace_back(path);
    } else if (path.size() < k && pathSum < n) {
      int start = path.empty() ? 1 : path.back() + 1;
      for (int idx = start; idx <= 9; ++idx) {
        path.emplace_back(idx);
        combinationSum3(k, n, pathSum + idx, path, result);
        path.pop_back();
      }
    }
  }
};
