class Solution {
public:
  enum OP { ADD = 0 - '+', SUB = 0 - '-', MUL = 0 - '*', DIV = 0 - '/' };

  // SLR(1)
  int calculate(string s) {

    // cout << ADD << endl;
    stack<int> stack;
    int tokenizer = 0;
    int token = nextToken(s, tokenizer);
    int prevRHS = token;
    stack.push(token);

    // first token should be number
    // assert(token >= 0);

    while ((token = nextToken(s, tokenizer)) != INT_MIN) {
      // num
      if (token >= 0) {
        // available for eval
        if (stack.size() == 2) {
          int op = stack.top();
          stack.pop();

          switch (op) {
          case ADD:
            stack.top() += token;
            prevRHS = token;
            break;
          case SUB:
            stack.top() -= token;
            prevRHS = -token;
            break;
          case MUL:
            stack.top() = (stack.top() - prevRHS) + prevRHS * token;
            prevRHS = prevRHS * token;
            break;
          case DIV:
            stack.top() = (stack.top() - prevRHS) + prevRHS / token;
            prevRHS = prevRHS / token;
            break;
            // default  : //error
            //           return INT_MIN;
          }
        } else {
          stack.push(token);
        }
      } else {
        stack.push(token);
      }
    }

    // for valid expr, assert(stack.size() == 1);
    return stack.top();
  }

  int nextToken(const string &s, int &idx) {
    // skip spaces
    while (idx < s.size() && s[idx] == ' ')
      ++idx;
    // no next token available
    if (idx < 0 || idx >= s.size())
      return INT_MIN;
    // OP
    if (s[idx] == '+' || s[idx] == '-' || s[idx] == '*' || s[idx] == '/') {
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
