class Solution {
public:
  bool isPalindrome(int x) {

    if (x < 0)
      return false;

    long a = x, b = 0;

    while (a) {
      b *= 10;
      b += a % 10;
      a /= 10;
    }

    return x == b;
  }
};
