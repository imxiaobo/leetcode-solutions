class Solution {
public:
  int removeDuplicates(vector<int> &nums) {

    auto first = nums.begin(), last = nums.begin();
    int count = 0, size = nums.size();
    if (size < 3)
      return size;

    while (last != nums.end()) {
      if (*first == *last) {
        ++last, ++count;
      } else {
        for (int i = 1, step = min(count, 2), num = *first; i < step; ++i) {
          *++first = num;
        }
        count = 0;
        *++first = *last;
      }
    }
    for (int i = 1, step = min(count, 2), num = *first; i < step; ++i) {
      *++first = num;
    }
    return 1 + distance(nums.begin(), first);
  }
};
