class Solution {
public:
  int evalRPN(vector<string> &tokens) {

    stack<int> stack;

    for (auto &token : tokens) {
      if (!isOp(token))
        stack.push(atoi(token.c_str()));
      else if (token == "+") {
        int rhs = stack.top();
        stack.pop();
        stack.top() += rhs;
      } else if (token == "-") {
        int rhs = stack.top();
        stack.pop();
        stack.top() -= rhs;
      } else if (token == "*") {
        int rhs = stack.top();
        stack.pop();
        stack.top() *= rhs;
      } else if (token == "/") {
        int rhs = stack.top();
        stack.pop();
        stack.top() /= rhs;
      }
    }

    return stack.top();
  }

  bool isOp(const string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
  }
};
