class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> permutations;
    generate(nums, nums.size(), 0, permutations);
    return permutations;
  }

  void generate(vector<int> &nums, int size, int idx,
                vector<vector<int>> &permutations) {
    if (idx == size) {
      permutations.emplace_back(nums);
    } else {
      for (int x = idx; x < size; ++x) {
        swap(nums[x], nums[idx]);
        generate(nums, size, idx + 1, permutations);
        swap(nums[x], nums[idx]);
      }
    }
  }
};
