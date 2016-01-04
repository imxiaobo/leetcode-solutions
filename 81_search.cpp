class Solution {
public:
  bool search(vector<int> &nums, int target) {

    if (nums.empty())
      return false;

    int minIdx = findMin(nums);
    // cout << "minidx: " << minIdx << endl;
    int maxIdx = (minIdx - 1 + nums.size()) % nums.size();

    while (maxIdx > 0 && nums[maxIdx] == nums[minIdx])
      --maxIdx;
    // cout << "maxIdx: " << maxIdx << endl;
    if (target < nums[minIdx] || target > nums[maxIdx])
      return false;

    if (target < nums[0])
      return search(nums, minIdx, nums.size() - 1, target) != -1;
    else
      return search(nums, 0, maxIdx, target) != -1;
  }

  int findMin(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[left] < nums[right])
        return left;
      else if (nums[left] == nums[right])
        ++left;
      else if (nums[left] <= nums[mid])
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
