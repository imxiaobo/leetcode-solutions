class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return "";
    sort(strs.begin(), strs.end());
    string &s1 = strs.front();
    string &s2 = strs.back();
    if (s1.empty() || s2.empty())
      return "";
    int i = 0;
    while (i < s1.size() && i < s2.size()) {
      if (s1[i] != s2[i])
        break;
      ++i;
    }
    return s1.substr(0, i);
  }
};
