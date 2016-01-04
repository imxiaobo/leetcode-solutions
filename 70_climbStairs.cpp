class Solution {
public:
  int climbStairs(int n) {

    if (n == 1)
      return 1;
    if (n == 2)
      return 2;

    int x = 3, fx1 = 2, fx2 = 1, fx;
    while (x <= n) {
      fx = fx1 + fx2;
      fx2 = fx1;
      fx1 = fx;
      x++;
    }

    return fx;
  }
};
