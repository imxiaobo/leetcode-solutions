class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string> &wordDict) {

    unordered_map<string, vector<string>> dp;
    int maxWordLen = 0;
    for (auto &w : wordDict)
      maxWordLen = max(maxWordLen, (int)w.size());
    return wordBreak(s, wordDict, "", maxWordLen, dp);
  }

  const vector<string> &wordBreak(const string &s,
                                  unordered_set<string> &wordDict,
                                  const string &bt, int maxWordLen,
                                  unordered_map<string, vector<string>> &dp) {
    vector<string> solutions;

    if (dp.find(s) != dp.end())
      return dp[s];
    else {
      int len = min((int)s.size(), maxWordLen);
      for (int n = 1; n <= len; ++n) {
        string word(s, 0, n);
        if (wordDict.find(word) != wordDict.end()) {
          string remain(s, n, s.size());
          if (remain.empty()) {
            solutions.emplace_back(move(word));
          } else {
            for (const auto &s :
                 wordBreak(remain, wordDict, word, maxWordLen, dp)) {
              solutions.emplace_back(word + " " + s);
            }
          }
        }
      }
    }

    dp.emplace(s, move(solutions));

    return dp[s];
  }
};
