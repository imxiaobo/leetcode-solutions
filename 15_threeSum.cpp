class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3)
      return {};

    sort(nums.begin(), nums.end());
    vector<vector<int>> results;

    int ai = 0, bi, ci;

    while (ai < nums.size() - 2) {
      int a = nums[ai];

      bi = ai + 1;
      ci = nums.size() - 1;

      while (bi < ci) {
        int b = nums[bi], c = nums[ci];

        int sum = a + b + c;

        if (sum > 0)
          while (ci > ai + 1 && nums[ci] == c)
            --ci;
        else if (sum < 0)
          while (bi < ci && nums[bi] == b)
            ++bi;
        else {
          results.push_back({a, b, c});
          while (ci > ai + 1 && nums[ci] == c)
            --ci;
          while (bi < ci && nums[bi] == b)
            ++bi;
        }
      }

      while (ai < nums.size() - 2 && nums[ai] == a)
        ++ai;
    }

    return results;
  }
};
