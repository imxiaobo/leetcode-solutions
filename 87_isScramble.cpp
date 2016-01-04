class Solution {
public:
  bool isScramble(string s1, string s2) {
    int sz = s1.size();
    if (sz != s2.size())
      return false;

    vector<vector<vector<int>>> memo(
        sz, vector<vector<int>>(sz, vector<int>(sz, -1)));
    return isScramble(s1, 0, s2, 0, sz, memo);
  }

  bool isScramble(const string &s1, int s1b, const string &s2, int s2b, int len,
                  vector<vector<vector<int>>> &memo) {
    auto &m = memo[s1b][s2b][len - 1];

    if (m != -1)
      return m;

    if (len == 1) {
      m = (s1[s1b] == s2[s2b]);
    } else {
      m = 0;

      for (int split = 1; split < len; ++split) {
        if (isScramble(s1, s1b, s2, s2b, split, memo) &&
            isScramble(s1, s1b + split, s2, s2b + split, len - split, memo)) {
          m = 1;
          break;
        }
        if (isScramble(s1, s1b, s2, s2b + len - split, split, memo) &&
            isScramble(s1, s1b + split, s2, s2b, len - split, memo)) {
          m = 1;
          break;
        }
      }
    }

    return m;
  }
};
