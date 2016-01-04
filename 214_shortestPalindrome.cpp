class Solution {
public:
  string shortestPalindrome(string s) {

    if (s.empty() || s.size() == 1)
      return s;

    string p = s;
    reverse(p.begin(), p.end());
    p = s + "#" + p;

    vector<int> next(p.size() + 1, 0);

    int k = -1, i = 0;
    next[0] = k;
    while (i < p.size()) {
      while (k >= 0 && p[k] != p[i])
        k = next[k];
      ++k, ++i;
      next[i] = k;
    }

    string suffix = s.substr(next.back());
    reverse(suffix.begin(), suffix.end());
    return suffix + s;
  }
};
