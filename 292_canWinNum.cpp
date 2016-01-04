class Solution {
public:
  bool canWinNim(int n) {
    int div = n / 4;
    int mod = n - 4 * div;
    switch (mod) {
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
    }
  }
};
