class Solution {
public:
  int numTrees(int n) {
    // (1...k-1),k,(k+1...n) ==> k = 1...n
    // f(0) = 1
    // f(1) = 1
    // f(2) = 2
    // f(k) = Sum(x, 0..k, f(x)*f(k-x))
    int *val = new int[n + 1];
    val[0] = 1;
    val[1] = 1;
    val[2] = 2;
    for (int k = 3; k <= n; ++k) {
      val[k] = 0;
      for (int x = 0; x < k; ++x) {
        val[k] += (val[x] * val[k - 1 - x]);
      }
    }

    return val[n];
  }
};
