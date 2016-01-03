class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {

    if (nums.size() < 3)
      return 0;

    sort(nums.begin(), nums.end());

    int ai = 0, bi, ci, minDiff = INT_MAX, closetSum = 0;

    while (ai < nums.size() - 2) {
      int a = nums[ai];

      bi = ai + 1;
      ci = nums.size() - 1;

      while (bi < ci) {
        int b = nums[bi], c = nums[ci];

        int sum = a + b + c;
        int diff = abs(sum - target);

        if (diff < minDiff) {
          closetSum = sum;
          minDiff = diff;
        }

        if (sum > target)
          while (ci > ai + 1 && nums[ci] == c)
            --ci;
        else if (sum < target)
          while (bi < ci && nums[bi] == b)
            ++bi;
        else {
          return sum;
        }
      }

      while (ai < nums.size() - 2 && nums[ai] == a)
        ++ai;
    }

    return closetSum;
  }
};
