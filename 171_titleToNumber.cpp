class Solution {
public:
  int titleToNumber(string s) {

    int val = 0;
    for (const char c : s) {
      val = val * 26 + (c - 'A' + 1);
    }

    return val;
  }
};
