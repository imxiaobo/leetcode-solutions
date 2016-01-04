class Solution {
public:
  bool wordPattern(string pattern, string str) {

    int pi = 0, si = 0;
    string m['z'];
    std::set<string> v;

    while (true) {
      if (pi == pattern.size())
        return si == str.size();
      if (si == str.size())
        return pi == pattern.size();

      char p = pattern[pi];

      string word;
      for (; si < str.size(); ++si) {
        if (str[si] != ' ')
          word += str[si];
        else {
          ++si;
          break;
        }
      }

      if (v.find(word) == v.end()) {
        if (!m[p].empty())
          return false;
        v.insert(word);
        m[p] = word;
      } else {
        if (m[p] != word)
          return false;
      }

      ++pi;
    }
  }
};
