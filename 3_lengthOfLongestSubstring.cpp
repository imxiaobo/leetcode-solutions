class Solution {
public:
  int lengthOfLongestSubstring(string s) {

    int window[256] = {0};
    int i = 0, j = 0, maxLen = 0;

    while (j < s.size()) {
      if (!window[s[j]]) {
        window[s[j++]] = 1;
        maxLen = max(maxLen, j - i);
      } else {
        while (i < j) {
          if (s[j] != s[i]) {
            window[s[i++]] = 0;
          } else {
            ++i, ++j;
            break;
          }
        }
      }
    }

    return maxLen;
  }
};
