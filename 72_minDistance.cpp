class Solution {
public:
  int minDistance(string word1, string word2) {
    return minDistanceDP(word1, word2);
  }

  int minDistanceDP(const string &word1, const string &word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));

    for (int w1i = 0; w1i <= word1.size(); ++w1i) {
      dp[w1i][0] = w1i;
    }

    for (int w2i = 0; w2i <= word2.size(); ++w2i) {
      dp[0][w2i] = w2i;
    }

    for (int w1i = 1; w1i <= word1.size(); ++w1i) {
      for (int w2i = 1; w2i <= word2.size(); ++w2i) {
        if (word1[w1i - 1] == word2[w2i - 1]) {
          dp[w1i][w2i] = dp[w1i - 1][w2i - 1];
        }
        // change, delete, insert
        else
          dp[w1i][w2i] = 1 + min(dp[w1i - 1][w2i - 1],
                                 min(dp[w1i - 1][w2i], dp[w1i][w2i - 1]));
      }
    }

    return dp[word1.size()][word2.size()];
  }
};
