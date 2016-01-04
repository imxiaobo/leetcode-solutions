class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int majority = nums[0];
    int count = 0;
    for (auto num : nums) {
      if (count == 0)
        majority = num;
      if (num == majority)
        ++count;
      else {
        --count;
      }
    }

    return majority;
  }
};
