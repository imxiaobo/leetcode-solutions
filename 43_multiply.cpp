class Solution {
public:
  string multiply(string num1, string num2) {

    if (num1 == "0" || num2 == "0")
      return "0";

    string result(num1.size() + num2.size(), '0');

    for (int x = num1.size() - 1; x >= 0; --x) {
      int carry = 0;
      for (int y = num2.size() - 1; y >= 0; --y) {
        int r = (num1[x] - '0') * (num2[y] - '0') + (result[x + y + 1] - '0') +
                carry;
        // cout << num1[x] << " " << num2[y] << " " << result[x + y + 1] << " "
        // << r << endl;
        result[x + y + 1] = (r % 10) + '0';
        carry = r / 10;
      }
      int z = x;
      while (carry) {
        int r = (result[z] - '0') + carry;
        result[z] = (r % 10) + '0';
        carry = r / 10;
        --z;
      }
    }

    if (result[0] == '0')
      return result.substr(1);
    else
      return result;
  }
};
