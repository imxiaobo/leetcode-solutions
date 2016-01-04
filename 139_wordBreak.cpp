class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &wordDict) {

    int maxLen = 0;
    for (const auto &w : wordDict)
      maxLen = max((int)w.size(), maxLen);

    vector<int> memo(s.size() + 1, -1);
    return wordBreak(s, 0, maxLen, wordDict, memo);
  }

  bool wordBreak(const string &s, int start, int maxLen,
                 unordered_set<string> &wordDict, vector<int> &memo) {
    if (memo[start] != -1)
      return memo[start];

    if (start == s.size())
      return (memo[start] = 1);

    for (int len = 1; len <= maxLen; ++len) {
      if (start + len > s.size())
        break;

      if (wordDict.find(s.substr(start, len)) != wordDict.end()) {
        if (wordBreak(s, start + len, maxLen, wordDict, memo)) {
          return (memo[start] = 1);
        }
      }
    }

    return (memo[start] = 0);
  }
};
