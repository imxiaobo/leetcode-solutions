class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {

    int XOR = 0, a = 0, b = 0, cmp = 0;
    for (int n : nums) {
      XOR ^= n;
    }

    cmp = XOR ^ (XOR - 1) & XOR;

    for (int n : nums) {
      cmp &n ? a ^= n : b ^= n;
    }

    return {a, b};
  }
};
