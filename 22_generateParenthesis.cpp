class Solution {
public:
  vector<string> generateParenthesis(int n) {
    string partial;
    vector<string> result;
    dfs(0, 0, n, partial, result);
    return result;
  }

  void dfs(int open, int close, int n, string &partial,
           vector<string> &result) {
    if (open <= n && close <= n) {
      if (open < n) {
        partial.push_back('(');
        dfs(open + 1, close, n, partial, result);
        partial.pop_back();
      }

      if (close < open) {
        partial.push_back(')');
        dfs(open, close + 1, n, partial, result);
        partial.pop_back();
      }

      if (open == n && close == n) {
        result.emplace_back(partial);
      }
    }
  }
};
