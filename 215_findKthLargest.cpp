class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    return findKthLargest(nums, 0, nums.size() - 1, k - 1);
  }

  int findKthLargest(vector<int> &nums, int from, int to, int k) {
    int pivot = partition(nums, from, to);
    if (pivot == k)
      return nums[k];
    if (pivot > k)
      return findKthLargest(nums, from, pivot - 1, k);
    if (pivot < k)
      return findKthLargest(nums, pivot + 1, to, k);
  }

  int partition(vector<int> &nums, int from, int to) {
    // select to as pivot
    int store = from;
    for (int idx = from; idx < to; ++idx) {
      if (nums[idx] > nums[to]) {
        swap(nums[store], nums[idx]);
        ++store;
      }
    }
    swap(nums[store], nums[to]);
    return store;
  }
};
