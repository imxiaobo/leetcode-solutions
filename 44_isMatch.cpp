class Solution {
public:
  bool isMatch(string s, string p) {

    int si = 0, pi = 0, star = -1, ri = 0;

    while (si < s.size()) {
      if (p[pi] == '*') {
        star = pi;
        ++pi;
        ri = si;
      } else if (p[pi] == s[si] || p[pi] == '?') {
        ++pi;
        ++si;
      } else if (star != -1) {
        pi = star + 1;
        si = ri + 1;
        ++ri;
      } else
        return false;
    }

    while (pi < p.size()) {
      if (p[pi] != '*')
        return false;
      ++pi;
    }
    return true;
  }
};
