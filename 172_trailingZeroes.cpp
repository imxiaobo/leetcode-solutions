class Solution {
public:
  int trailingZeroes(int n) {
    int fives = 0;
    while (n) {
      n /= 5;
      fives += n;
    }
    return fives;
  }
};
