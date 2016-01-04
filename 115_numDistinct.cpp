class Solution {
public:
  int numDistinct(const string &s, const string &t) {

    if (s.size() < t.size())
      return 0;

    vector<int> prefix(t.size() + 1, 0);
    prefix[0] = 1;

    for (auto c : s) {
      for (int x = t.size(); x > 0; --x) {
        prefix[x] += c == t[x - 1] ? prefix[x - 1] : 0;
      }
    }

    return prefix.back();
  }
};
