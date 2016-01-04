class Solution {
public:
  int compareVersion(string version1, string version2) {

    vector<int> v1, v2;
    parse(version1, v1);
    parse(version2, v2);

    auto i1 = v1.begin(), i2 = v2.begin();

    while (i1 != v1.end() && i2 != v2.end()) {
      if (*i1 > *i2)
        return 1;
      if (*i1 < *i2)
        return -1;
      ++i1, ++i2;
      if (i1 == v1.end() && i2 != v2.end()) {
        while (i2 != v2.end()) {
          if (*i2 != 0)
            return -1;
          ++i2;
        }
      } else if (i2 == v2.end() && i1 != v1.end()) {
        while (i1 != v1.end()) {
          if (*i1 != 0)
            return 1;
          ++i1;
        }
      }
    }

    return 0;
  }

  void parse(const string &version, vector<int> &v) {
    int b = 0, e = 0;
    while (e < version.size()) {
      while (e < version.size() && version[e] != '.')
        ++e;
      v.push_back(atoi(version.substr(b, e).c_str()));
      b = e + 1;
      e = b;
    }
  }
};
