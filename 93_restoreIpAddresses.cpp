class Solution {
public:
  vector<string> restoreIpAddresses(string s) {

    vector<string> result;
    dfs(s, 0, "", 0, result);
    return move(result);
  }

  void dfs(const string &s, int start, string partial, int parts,
           vector<string> &result) {
    if (parts == 4 && start == s.size()) {
      result.emplace_back(partial);
    } else if (parts < 4 && start < s.size()) {
      for (int x = 1; x <= (s[start] == '0' ? 1 : 3); ++x) {
        auto ns = s.substr(start, x);
        int n = atoi(ns.c_str());
        if (n <= 255) {
          string next = partial;
          if (!next.empty())
            next.push_back('.');
          next.append(ns);
          dfs(s, start + x, move(next), parts + 1, result);
        }
      }
    }
  }
};
