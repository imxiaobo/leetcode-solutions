class Solution {
public:
  void moveZeroes(vector<int> &nums) {

    auto first = nums.begin(), last = first, end = nums.end();
    while (last != end) {
      if (*last == 0) {
        ++last;
      } else {
        iter_swap(first++, last++);
      }
    }
  }
};
