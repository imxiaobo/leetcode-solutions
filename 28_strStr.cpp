class Solution {
public:
  int strStr(string haystack, string needle) {

    if (needle.empty())
      return 0;
    if (needle.size() > haystack.size())
      return -1;

    vector<int> next = kmpNext(needle);

    int ni = 0, hi = 0;
    while (hi < haystack.size() && ni < needle.size()) {
      if (haystack[hi] == needle[ni]) {
        if (ni == needle.size() - 1)
          return hi - ni;
        ++hi, ++ni;
      } else if (ni > 0) {
        ni = next[ni];
      } else {
        ++hi;
      }
    }

    return -1;
  }

  vector<int> kmpNext(const string &p) {
    vector<int> next(p.size() + 1, 0);
    int k = -1, i = 0;
    next[i] = k;
    while (i < p.size()) {
      while (k >= 0 && p[i] != p[k])
        k = next[k];
      next[++i] = ++k;
    }
    return move(next);
  }
};
