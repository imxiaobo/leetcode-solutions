class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
    vector<string> palindromes;
    vector<vector<string>> result;
    partition(s, 0, palindromes, result, memo);
    return move(result);
  }

  void partition(const string &s, int begin, vector<string> &palindromes,
                 vector<vector<string>> &result, vector<vector<int>> &memo) {
    if (begin == s.size()) {
      result.emplace_back(palindromes);
    } else {
      for (int end = begin; end < s.size(); ++end) {
        if (isPalindrome(s, begin, end, memo)) {
          palindromes.emplace_back(s, begin, end - begin + 1);
          partition(s, end + 1, palindromes, result, memo);
          palindromes.pop_back();
        }
      }
    }
  }

  bool isPalindrome(const string &s, int begin, int end,
                    vector<vector<int>> &memo) {
    auto &m = memo[begin][end];
    if (m != -1)
      return m;
    if ((begin == end) || (begin + 1 == end))
      return m = (s[begin] == s[end]);
    if (s[begin] == s[end])
      return m = isPalindrome(s, begin + 1, end - 1, memo);
    return m = 0;
  }
};
