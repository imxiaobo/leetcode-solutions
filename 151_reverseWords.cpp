class Solution {
public:
  void reverseWords(string &s) {

    if (s.empty())
      return;
    // clean up spaces
    if (s.front() == ' ') {
      int e = 0;
      while (e < s.size() && s[e] == ' ')
        ++e;
      s.erase(0, e);
      // cout << s << endl;
    }
    if (s.back() == ' ') {
      int b = s.size() - 1;
      while (b >= 0 && s[b] == ' ')
        --b;
      s.erase(b + 1);
      // cout << s << endl;
    }

    if (s.empty())
      return;

    auto it = s.begin();
    while (it != s.end()) {
      if (*it == ' ' && *(it + 1) == ' ') {
        it = s.erase(it);
      } else {
        ++it;
      }
    }
    // cout << s << endl;
    reverse(s.begin(), s.end());
    // cout << s << endl;

    // reverse word
    auto ib = s.begin(), ie = ib;
    while (true) {
      while (ie != s.end() && *ie != ' ')
        ++ie;
      reverse(ib, ie);
      // cout << s << endl;
      if (ie == s.end())
        break;
      ib = ie + 1;
      ie = ib;
    }
  }
};
