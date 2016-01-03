class Solution {
public:
  void nextPermutation(vector<int> &nums) {

    if (nums.size() <= 1)
      return;

    auto right = nums.rbegin();
    auto left = right + 1;

    while (left != nums.rend()) {
      if (*left < *right)
        break;
      ++left;
      ++right;
    }

    if (left == nums.rend()) {
      reverse(nums.begin(), nums.end());
    } else {
      right = nums.rbegin();
      while (*right <= *left)
        ++right;
      iter_swap(left, right);
      reverse(nums.rbegin(), left);
    }
  }
};
