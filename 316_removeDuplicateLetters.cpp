class Solution {
public:
  string removeDuplicateLetters(string s) {
    vector<int> count(26, 0);
    for (char c : s)
      ++count[c - 'a'];
    vector<int> inResult(26, 0);

    string result;
    for (char c : s) {
      if (!inResult[c - 'a']) {
        while (!result.empty() && result.back() >= c &&
               count[result.back() - 'a'] > 0) {
          inResult[result.back() - 'a'] = 0;
          result.pop_back();
        }
        result.push_back(c);
        inResult[c - 'a'] = 1;
      }
      --count[c - 'a'];
    }
    return result;
  }
};
