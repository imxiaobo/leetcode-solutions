class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> stack;
    stack.push(-1);
    int len = 0;
    for (int idx = 0; idx < s.size(); ++idx) {
      if (s[idx] == '(') {
        stack.push(idx);
      } else {
        stack.pop();
        if (!stack.empty()) {
          len = max(len, idx - stack.top());
        } else {
          stack.push(idx);
        }
      }
    }
    return len;
  }
};
