class Solution {
public:
  string addBinary(string a, string b) {

    if (a.size() < b.size())
      swap(a, b);

    // a > b

    int carry = 0;
    int ai = a.size() - 1;
    int bi = b.size() - 1;
    while (ai >= 0 && bi >= 0) {
      int sum = (int)(a[ai] - '0') + (int)(b[bi] - '0') + carry;
      carry = sum / 2;
      sum %= 2;
      a[ai] = (char)sum + '0';
      --ai;
      --bi;
    }

    while (ai >= 0 && carry != 0) {
      int sum = (int)(a[ai] - '0') + carry;
      carry = sum / 2;
      sum %= 2;
      a[ai] = (char)sum + '0';
      --ai;
    }

    if (ai >= 0)
      return a;
    else {
      if (carry != 0)
        return "1" + a;
      else
        return a;
    }
  }
};
