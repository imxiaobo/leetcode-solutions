class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() < 2)
      return nums.size();
    auto first = nums.begin(), last = nums.begin();
    while (last != nums.end()) {
      if (*last == *first)
        ++last;
      else
        *(++first) = *last;
    }
    return first - nums.begin() + 1;
  }
};
