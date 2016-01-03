class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {

    int of = 0;
    vector<int> result;

    int sum = digits.back() + 1;
    of = sum / 10;
    digits.back() = sum % 10;

    for (int bit = digits.size() - 2; bit >= 0; --bit) {
      sum = digits[bit] + of;
      of = sum / 10;
      digits[bit] = sum % 10;
    }

    if (of != 0) {
      result.push_back(of);
    }
    for (auto d : digits) {
      result.push_back(d);
    }
    return result;
  }
};
