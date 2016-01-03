class Solution {
public:
  int lengthOfLastWord(string s) {

    if (s.empty())
      return 0;

    int e = s.size() - 1;
    int b = e;

    while (e >= 0 && s[e] == ' ')
      --e;
    if (e < 0)
      return 0;

    b = e;
    while (b >= 0 && s[b] != ' ')
      --b;

    return e - b;
  }
};
