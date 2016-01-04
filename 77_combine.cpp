class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> combination;
    vector<vector<int>> combinations;

    combine(n, k, 1, combination, combinations);

    return combinations;
  }

  int combine(int n, int k, int next, vector<int> &combination,
              vector<vector<int>> &combinations) {
    if (combination.size() == k) {
      combinations.emplace_back(combination);
    } else {
      for (int idx = next;
           idx <= n && ((k - combination.size()) <= (n - idx + 1)); ++idx) {
        combination.emplace_back(idx);
        combine(n, k, idx + 1, combination, combinations);
        combination.pop_back();
      }
    }
  }
};
