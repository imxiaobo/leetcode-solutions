class Solution {
public:
  int search(vector<int> &nums, int target) {
    if (nums.empty())
      return -1;

    int minIdx = findMin(nums);
    int maxIdx = (minIdx - 1 + nums.size()) % nums.size();
    if (target < nums[minIdx] || target > nums[maxIdx])
      return -1;

    if (target < nums[0])
      return search(nums, minIdx, nums.size() - 1, target);
    else
      return search(nums, 0, maxIdx, target);
  }

  int findMin(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[left] < nums[right])
        return left;
      if (nums[left] <= nums[mid])
        left = mid + 1;
      else
        right = mid;
    }

    return left;
  }

  int search(vector<int> &nums, int first, int last, int target) {
    while (first <= last) {
      int mid = first + (last - first) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target)
        last = mid - 1;
      else
        first = mid + 1;
    }
    return -1;
  }
};
