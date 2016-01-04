class Solution {
public:
  bool isAdditiveNumber(string num) {

    int len = num.size();
    if (len < 3)
      return false;

    for (int len1 = 1; len1 <= len / 2; ++len1) {
      for (int len2 = 1; len - len1 - len2 >= max(len1, len2); ++len2) {
        if (isAdditiveNumber(num, len, 0, len1, len2))
          return true;
      }
    }

    return false;
  }

  // need dp to speed up
  bool isAdditiveNumber(string num, int len, int start, int len1, int len2) {
    // check leading zero
    if ((num[start] == '0' && len1 != 1) ||
        (num[start + len1] == '0' && len2 != 1))
      return false;

    // exit condition
    if (start + len1 + len2 == len)
      return true;

    // calculate sum of preceding 2 numbers
    string num3 = sum(num.substr(start, len1), num.substr(start + len1, len2));
    int len3 = num3.size();

    // orz...
    if (num3 != num.substr(start + len1 + len2, len3))
      return false;

    // tail recursion...
    return isAdditiveNumber(num, len, start + len1, len2, len3);
  }

  string sum(string num1, string num2) {
    if (num1.size() < num2.size())
      swap(num1, num2);

    string result = "0";
    result += num1;

    int carry = 0;
    auto it2 = num2.rbegin(), itr = result.rbegin();

    while (it2 != num2.rend()) {
      int sum = *it2 - '0' + *itr - '0' + carry;
      *itr = sum % 10 + '0';
      carry = sum / 10;
      ++it2, ++itr;
    }

    while (carry) {
      int sum = *itr - '0' + carry;
      *itr = sum % 10 + '0';
      carry = sum / 10;
      ++itr;
    }

    if (result[0] == '0')
      return result.substr(1);
    return result;
  }
};
