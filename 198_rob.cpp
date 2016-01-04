class Solution {
public:
  int rob(vector<int> &nums) {
    int inclusive = 0, exclusive = 0;
    for (auto n : nums) {
      int tmp = inclusive;
      inclusive = exclusive + n;
      exclusive = max(exclusive, tmp);
    }
    return max(inclusive, exclusive);
  }
};
