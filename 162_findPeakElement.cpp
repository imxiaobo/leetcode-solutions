class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    if (nums.size() == 1)
      return 0;
    int left = 0, right = nums.size() - 1;
    // num[left - 1] < num[left], num[right] > num[right + 1]
    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid + 1] > nums[mid])
        left = mid + 1;
      else if (nums[mid - 1] > nums[mid])
        right = mid - 1;
      else
        return mid;
    }

    return nums[left] > nums[right] ? left : right;
  }
};
