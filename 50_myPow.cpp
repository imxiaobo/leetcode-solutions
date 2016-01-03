class Solution {
public:
  double myPow(double x, int n) {

    double result = 1.0;
    unsigned int p;

    if (n < 0) {
      p = -n;
      x = 1 / x;
    } else {
      p = n;
    }

    while (p) {
      if (p & 1)
        result *= x;
      x *= x;
      p >>= 1;
    }

    return result;
  }
};
