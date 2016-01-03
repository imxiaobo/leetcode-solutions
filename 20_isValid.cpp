class Solution {
public:
  bool isValid(string s) {
    stack<char> open;
    for (string::const_iterator i = s.begin(); i != s.end(); ++i) {
      switch (*i) {
      case '(':
      case '[':
      case '{': {
        open.push(*i);
        continue;
      }
      case ')': {
        if (open.empty() || open.top() != '(')
          return false;
        open.pop();
        continue;
      }
      case ']': {
        if (open.empty() || open.top() != '[')
          return false;
        open.pop();
        continue;
      }
      case '}': {
        if (open.empty() || open.top() != '{')
          return false;
        open.pop();
        continue;
      }
      default:
        continue;
      }
    }
    return open.empty();
  }
};
