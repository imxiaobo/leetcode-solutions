class Solution {
public:
  int findMin(vector<int> &nums) {

    int left = 0, right = nums.size() - 1;
    // invariant
    while (nums[left] >= nums[right]) {
      int mid = left + (right - left) / 2;
      if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
        int result = nums[left];
        for (int idx = left + 1; idx <= right; ++idx) {
          result = min(result, nums[idx]);
        }
        return result;
      } else if (nums[mid] <= nums[right])
        right = mid;
      else
        left = mid + 1;
    }
    return nums[left];
  }
};
