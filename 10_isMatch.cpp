class Solution {
public:
  bool isMatch(string s, string p) {
    vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
    return isMatch(s, 0, p, 0, memo);
  }

  bool isMatch(const string &s, int si, const string &p, int pi,
               vector<vector<int>> &memo) {
    if (memo[si][pi] != -1)
      return memo[si][pi];

    if (pi == p.size() && si == s.size())
      return memo[si][pi] = true;
    if (pi == p.size() && si < s.size())
      return memo[si][pi] = false;
    if (si == s.size() && pi < p.size()) {
      int x = pi + 1;
      while (x < p.size()) {
        if (p[x] != '*')
          return memo[si][pi] = false;
        x += 2;
      }
      return memo[si][pi] = (x != p.size());
    }

    if (pi + 1 < p.size() && p[pi + 1] != '*') {
      if (s[si] == p[pi] || p[pi] == '.') {
        return memo[si][pi] = isMatch(s, si + 1, p, pi + 1, memo);
      } else
        return memo[si][pi] = false;
    } else if (pi + 1 < p.size() && p[pi + 1] == '*') {
      if (s[si] == p[pi] || p[pi] == '.') {
        int x = si;
        while (x == s.size() || s[x] == p[pi] || p[pi] == '.') {
          if (isMatch(s, x, p, pi + 2, memo))
            return memo[si][pi] = true;
          if (x == s.size())
            break;
          ++x;
        }
        return memo[si][pi] = isMatch(s, x, p, pi + 2, memo);
      } else {
        return memo[si][pi] = isMatch(s, si, p, pi + 2, memo);
      }
    } else {
      if (s[si] == p[pi] || p[pi] == '.') {
        return memo[si][pi] = isMatch(s, si + 1, p, pi + 1, memo);
      } else
        return memo[si][pi] = false;
    }
  }
};
