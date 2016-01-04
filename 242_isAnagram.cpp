class Solution {
public:
  bool isAnagram(string s, string t) {

    if (s.size() != t.size())
      return false;

    int S[26] = {0}, T[26] = {0};

    for (char c : s) {
      ++S[c - 'a'];
    }

    for (char c : t) {
      ++T[c - 'a'];
    }

    for (int i = 0; i < 25; ++i) {
      if (S[i] != T[i])
        return false;
    }
    return true;
  }
};
