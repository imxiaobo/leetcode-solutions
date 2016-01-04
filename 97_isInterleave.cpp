class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size())
      return false;
    vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    return isInterleave(s1, 0, s2, 0, s3, 0, memo);
  }

  bool isInterleave(const string &s1, int i, const string &s2, int j,
                    const string &s3, int k, vector<vector<int>> &memo) {
    auto &m = memo[i][j];
    if (m != -1)
      return m;
    else {
      if (i == s1.size())
        return m = (s2.substr(j) == s3.substr(k));
      if (j == s2.size())
        return m = (s1.substr(i) == s3.substr(k));
      else {
        if (s1[i] == s2[j]) {

          return m = (s1[i] == s3[k]) &&
                     (isInterleave(s1, i + 1, s2, j, s3, k + 1, memo) ||
                      isInterleave(s1, i, s2, j + 1, s3, k + 1, memo));
        } else {
          if (s1[i] == s3[k])
            return m = isInterleave(s1, i + 1, s2, j, s3, k + 1, memo);
          if (s2[j] == s3[k])
            return m = isInterleave(s1, i, s2, j + 1, s3, k + 1, memo);
          else
            return m = 0;
        }
      }
    }
  }
};
