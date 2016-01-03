class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    auto pivot = partition(candidates.begin(), candidates.end(),
                           [target](const int &i) { return i <= target; });

    partial_sort(candidates.begin(), pivot, candidates.end());

    vector<int> combination;
    vector<vector<int>> combinations;

    combinationSum(candidates.begin(), pivot, target, 0, combination,
                   combinations);

    return move(combinations);
  }

  void combinationSum(vector<int>::const_iterator first,
                      vector<int>::const_iterator last, int target, int sum,
                      vector<int> &combination,
                      vector<vector<int>> &combinations) {
    if (sum == target) {
      combinations.emplace_back(combination);
    }
    // all positive
    else if (sum < target) {
      while (first != last) {
        int nextSum = sum + *first;
        if (nextSum <= target) {
          combination.emplace_back(*first);
          combinationSum(first, last, target, nextSum, combination,
                         combinations);
          combination.pop_back();
          ++first;
        } else {
          break;
        }
      }
    }
  }
};
