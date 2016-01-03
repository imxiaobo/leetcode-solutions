class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {

    vector<vector<int>> all;

    sort(nums.begin(), nums.end());

    do {
      all.push_back(nums);

    } while (next_perm(nums));

    return all;
  }

  bool next_perm(vector<int> &nums) {
    if (nums.size() <= 1)
      return false;

    auto right = nums.rbegin();
    auto left = right + 1;

    while (left != nums.rend()) {
      if (*left < *right)
        break;
      ++left;
      ++right;
    }

    if (left == nums.rend()) {
      return false;
    } else {
      right = nums.rbegin();

      while (*right <= *left)
        ++right;

      iter_swap(left, right);

      reverse(nums.rbegin(), left);
    }

    return true;
  }
};
