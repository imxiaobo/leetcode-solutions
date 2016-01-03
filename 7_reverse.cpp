class Solution {
public:
  int reverse(int x) {

    long sign = x > 0 ? 1 : -1;
    long a = abs((long)x);
    long b = 0;

    while (a) {
      b *= 10;
      b += a % 10;
      a /= 10;
    }

    long result = b * sign;

    if (result < INT_MIN || result > INT_MAX)
      return 0;
    return result;
  }
};
