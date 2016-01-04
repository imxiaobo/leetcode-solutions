class Solution {
public:
  int findMin(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;

    // invariant: nums[left] > nums[right]
    while (nums[left] > nums[right]) {
      int mid = left + (right - left) / 2;
      // if (nums[mid] < nums[right]) right = mid;
      // else left = mid + 1;
      if (nums[left] <= nums[mid])
        left = mid + 1;
      else
        right = mid;
    }
    return nums[left];
  }
};
