class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {

    if (numerator == 0)
      return "0";

    string result;
    long n = labs(numerator), d = labs(denominator);
    if ((numerator < 0) ^ (denominator < 0))
      result.push_back('-');

    result.append(to_string(n / d));

    long r = n % d;
    if (r == 0)
      return result;
    result.push_back('.');
    r *= 10;
    unordered_map<long, int> m;
    while (r) {
      if (m.find(r) != m.end()) {
        result.insert(m[r], 1, '(');
        result.push_back(')');
        break;
      } else {
        m[r] = result.size();
        result.push_back(r / d + '0');
        r = (r % d) * 10;
      }
    }
    return result;
  }
};
