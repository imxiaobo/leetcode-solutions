class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {

    const int size = nums.size();
    if (size == 0)
      return 1;

    for (int idx = 0; idx < size; ++idx) {
      while (nums[idx] > 0 && nums[idx] < size &&
             nums[idx] != nums[nums[idx] - 1]) {
        swap(nums[idx], nums[nums[idx] - 1]);
      }
    }

    for (int idx = 0; idx < size; ++idx) {
      if (nums[idx] != idx + 1) {
        return idx + 1;
      }
    }

    return nums.back() + 1;
  }
};
