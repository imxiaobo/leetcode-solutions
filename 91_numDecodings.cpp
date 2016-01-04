class Solution {
public:
  int numDecodings(string s) {
    if (s.empty())
      return 0;
    vector<int> memo(s.size(), -1);
    memo.back() = s.back() == '0' ? 0 : 1;
    return numDecodings(s, 0, memo);
  }

  int numDecodings(const string &s, int start, vector<int> &memo) {
    if (start >= s.size())
      return 1;

    if (memo[start] != -1)
      return memo[start];

    if (s[start] == '0') {
      memo[start] = 0;
    } else {
      int n = atoi(s.substr(start, 2).c_str());

      if (n <= 26) {
        memo[start] =
            numDecodings(s, start + 1, memo) + numDecodings(s, start + 2, memo);
      } else {
        memo[start] = numDecodings(s, start + 1, memo);
      }
    }

    return memo[start];
  }
};
