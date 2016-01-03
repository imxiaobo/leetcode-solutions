class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {

    if (nums.size() < 4)
      return {};

    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    for (int i = 0; i <= nums.size() - 4; ++i) {
      for (int j = i + 1; j <= nums.size() - 3; ++j) {
        int k = j + 1, l = nums.size() - 1;

        while (k < l) {
          int sum = nums[i] + nums[j] + nums[k] + nums[l];
          // cout << i << ":" << j << ":" << k << ":" << l << endl;
          // cout << sum << endl;
          if (sum < target) {
            do {
              ++k;
            } while (k < l && nums[k] == nums[k - 1]);
          } else if (sum > target) {
            do {
              --l;
            } while (k < l && nums[l] == nums[l + 1]);
          } else {
            result.push_back({nums[i], nums[j], nums[k], nums[l]});
            do {
              ++k;
            } while (k < l && nums[k] == nums[k - 1]);
            do {
              --l;
            } while (k < l && nums[l] == nums[l + 1]);
          }
        }

        do {
          ++j;
        } while (j <= nums.size() - 3 && nums[j] == nums[j - 1]);
        --j;
      }

      do {
        ++i;
      } while (i == 0 || (i <= nums.size() - 4 && nums[i] == nums[i - 1]));
      --i;
    }

    return result;
  }
};
