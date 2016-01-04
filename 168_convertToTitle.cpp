class Solution {
public:
  string convertToTitle(int n) {

    string s;
    while (n >= 1) {
      s = string() + (char)('A' + (n - 1) % 26) + s;
      n = (n - 1) / 26;
    }

    return s;
  }
};
