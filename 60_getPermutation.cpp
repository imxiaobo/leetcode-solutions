class Solution {
public:
  // n = 3, k = 5
  string getPermutation(int n, int k) {

    string result;

    vector<int> factorial;
    vector<int> digits;

    factorial.push_back(1);
    for (int x = 1; x <= n; ++x) {
      factorial.push_back(x * factorial.back());
      digits.push_back(x);
    }

    // for (k; n > 0; --n)
    for (k--; n > 0; --n) {

      // int digit = digits[(k / factorial - 1 + n) % n];
      int digit = digits[k / factorial[n - 1]];
      // cout << (k / factorial[n - 1]) << " : " << digit << endl;

      result.push_back(digit + '0');

      digits.erase(remove(digits.begin(), digits.end(), digit), digits.end());

      k %= factorial[n - 1];
    }

    return result;
  }
};
