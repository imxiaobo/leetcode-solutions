class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> result;
    string path;
    dfs(s, 0, 0, path, result);
    return vector<string>(result.begin(), result.end());
  }

  void dfs(const string &s, int start, int open, string &path,
           unordered_set<string> &result) {
    if (start == s.size() && open == 0) {
      if (result.empty() || path.size() == result.begin()->size()) {
        result.emplace(path);
      }
    } else if (start < s.size() && open >= 0) {
      // preserve
      path.push_back(s[start]);
      if (s[start] == '(') {
        dfs(s, start + 1, open + 1, path, result);
      } else if (s[start] == ')') {
        dfs(s, start + 1, open - 1, path, result);
      } else {
        dfs(s, start + 1, open, path, result);
      }
      path.pop_back();

      // remove
      if (s[start] == '(' || s[start] == ')') {
        auto c = s[start];
        while (s[start] == c)
          ++start;
        dfs(s, start, open, path, result);
      }
    }
  }
};

/*
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;
        q.emplace(s);
        visited.emplace(s);

        while (!q.empty())
        {
          auto t = move(q.front());
          q.pop();
          if (isValid(t) && (result.empty() || t.size() ==
result.front().size()))
          {
            result.emplace_back(move(t));
          }
          else if (result.empty())
          {
            for (int idx = 0; idx < t.size(); ++idx)
            {
              if (t[idx] == '(' || t[idx] == ')')
              {
                string next = t.substr(0, idx);
                if (idx != t.size() - 1) next += t.substr(idx + 1);
                if (visited.find(next) == visited.end())
                {
                  q.emplace(next);
                  visited.emplace(next);
                }
              }
            }
          }
        }
        return move(result);
    }

    bool isValid(const string& s)
    {
      int open = 0;
      for (char c : s)
      {
        if (c == '(')
        {
          ++open;
        }
        else if (c == ')')
        {
          if (--open < 0) return false;
        }
      }
      return open == 0;
    }

};
*/
