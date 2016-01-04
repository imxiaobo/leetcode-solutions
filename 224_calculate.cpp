class Solution {

  enum OP { ADD = 0 - '+', SUB = 0 - '-', OPP = 0 - '(', CLP = 0 - ')' };

public:
  int calculate(string s) {

    stack<int> e;
    int tokenizer = 0;
    int token;

    while ((token = nextToken(s, tokenizer)) != INT_MIN) {
      processToken(token, (token >= 0), e);
    }

    return e.top();
  }

  void processToken(int token, bool isNumber, stack<int> &e) {
    // OP
    if (!isNumber) {
      if (token == CLP) {
        int t = e.top();
        e.pop();
        e.pop();
        processToken(t, true, e);
      } else {
        e.push(token);
      }
    }
    // NUM
    else {
      if (e.empty() || e.top() == OPP) {
        e.push(token);
      } else {
        if (e.top() == ADD) {
          e.pop();
          e.top() += token;
        } else {
          e.pop();
          e.top() -= token;
        }
      }
    }
  }

  int nextToken(const string &s, int &idx) {
    // skip spaces
    while (idx < s.size() && s[idx] == ' ')
      ++idx;
    // no next token available
    if (idx >= s.size())
      return INT_MIN;
    // OP
    if (s[idx] == '+' || s[idx] == '-' || s[idx] == '(' || s[idx] == ')') {
      return -s[idx++];
    }
    // NUM
    else {
      int val = 0;
      while (idx < s.size() && isdigit(s[idx])) {
        val = val * 10 + s[idx] - '0';
        ++idx;
      }
      return val;
    }
  }
};
