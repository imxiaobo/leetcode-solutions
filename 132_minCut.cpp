class Solution {
public:
  int minCut(string s) {

    int size = s.size();

    vector<int> cuts(size + 1, INT_MAX);
    cuts[size] = -1;

    vector<vector<int>> palindrome(size, vector<int>(size, -1));

    return minCut(s, 0, size, cuts, palindrome);
  }

  // with memoization
  int minCut(const string &s, int start, int size, vector<int> &cuts,
             vector<vector<int>> &palindrome) {
    if (cuts[start] != INT_MAX)
      return cuts[start];

    for (int end = size - 1; end >= start; --end) {
      if (isPalindrome(s, start, end, palindrome)) {
        cuts[start] =
            min(cuts[start], 1 + minCut(s, end + 1, size, cuts, palindrome));
      }
    }

    return cuts[start];
  }

  // with memoization
  bool isPalindrome(const string &s, int from, int to,
                    vector<vector<int>> &palindrome) {
    auto &result = palindrome[from][to];

    if (result == -1) {
      if (from == to)
        result = 1;
      else if (from == to - 1)
        result = (s[from] == s[to] ? 1 : 0);
      else if (s[from] == s[to])
        result = isPalindrome(s, from + 1, to - 1, palindrome);
      else
        result = 0;
    }

    return result;
  }
};
