class Solution {
public:
  bool isPalindrome(string s) {

    if (s.empty())
      return true;

    int forward = 0;
    int backward = s.size() - 1;

    while (forward < backward) {
      // skip irrelevant characters
      while (forward < s.size() && !isalnum(s[forward]))
        ++forward;
      while (backward >= 0 && !isalnum(s[backward]))
        --backward;
      if (forward >= backward)
        break;

      // alpha
      if (!isdigit(s[forward])) {
        if (toupper(s[forward]) != toupper(s[backward]))
          return false;
      }
      // num
      else {
        if (s[forward] != s[backward])
          return false;
      }

      ++forward, --backward;
    }

    return true;
  }
};
