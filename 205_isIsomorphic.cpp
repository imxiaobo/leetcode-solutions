class Solution {
public:
  bool isIsomorphic(string s, string t) {

    char isomorphicMapping[128]{'\0'};
    bool hasMapping[128]{false};

    for (int idx = 0; idx < s.size(); ++idx) {
      char key = s[idx], val = t[idx];
      if (isomorphicMapping[key] != '\0') {
        if (isomorphicMapping[key] != val)
          return false;
      } else if (hasMapping[val]) {
        return false;
      } else {
        isomorphicMapping[key] = val;
        hasMapping[val] = true;
      }
    }
    return true;
  }
};
