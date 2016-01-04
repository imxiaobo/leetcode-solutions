class Solution {
public:
  int mySqrt(int x) {
    assert(x >= 0);
    if (x == 0)
      return 0;
    unsigned int r = x;
    while (r > x / r)
      r = ((r + x / r) >> 1);
    return r;
  }
};
