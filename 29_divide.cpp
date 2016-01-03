class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 0)
      return INT_MAX;
    if (dividend == 0)
      return 0;

    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    long a = labs(dividend), b = labs(divisor);
    long result = 0, x = 0;

    while (a >= b) {
      while (a >= (b << x))
        ++x;
      a -= b << (x - 1);
      result += 1L << (x - 1);
      x = 0;
    }

    if (sign < 0)
      return -result;
    else {
      if (result == (long)INT_MAX + 1)
        --result;
      return result;
    }
  }
};
