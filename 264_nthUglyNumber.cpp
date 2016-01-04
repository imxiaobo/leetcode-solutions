class Solution {
public:
  int nthUglyNumber(int n) {

    vector<int> uglyNumbers = {1};
    uglyNumbers.reserve(n);

    int two = 0, three = 0, five = 0;
    while (uglyNumbers.size() < n) {
      int next = min(uglyNumbers[two] * 2,
                     min(uglyNumbers[three] * 3, uglyNumbers[five] * 5));

      uglyNumbers.push_back(next);

      if (next == uglyNumbers[two] * 2)
        ++two;
      if (next == uglyNumbers[three] * 3)
        ++three;
      if (next == uglyNumbers[five] * 5)
        ++five;
    }
    return uglyNumbers.back();
  }
};
