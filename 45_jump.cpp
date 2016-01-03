class Solution {
public:
  int jump(vector<int> &nums) {

    int size = nums.size();
    if (size <= 1)
      return 0;

    int rangeLeft = 0;
    int rangeRight = nums[0];

    if (rangeRight >= size - 1)
      return 1;

    int step = 1;

    while (rangeRight < size) {
      int reachable = rangeLeft;

      for (int i = rangeLeft; i <= rangeRight; ++i) {
        reachable = max(reachable, nums[i] + i);
        if (reachable >= size - 1)
          return step + 1;
      }

      if (reachable <= rangeRight)
        return -1;

      ++step;

      rangeLeft = rangeRight;
      rangeRight = reachable;
    }
  }
};
