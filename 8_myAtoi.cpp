class Solution {
public:
  int myAtoi(string str) {
    // check empty
    if (str.empty())
      return 0;
    // discard leading spaces
    auto it = str.begin();
    while (it != str.end() && isspace(*it))
      ++it;

    // sign
    int sign = 1;
    if (it == str.end()) {
      return 0;
    } else if (*it == '+') {
      ++it;
    } else if (*it == '-') {
      sign = -1;
      ++it;
    } else if (!isdigit(*it))
      return 0;

    long val = 0;
    while (it != str.end() && isdigit(*it)) {
      val *= 10;
      val += (*it - '0');
      ++it;
      // check overflow
      if (val * sign < INT_MIN)
        return INT_MIN;
      else if (val * sign > INT_MAX)
        return INT_MAX;
    }

    return val * sign;
  }
};
