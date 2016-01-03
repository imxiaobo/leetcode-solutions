class Solution {
public:
  int romanToInt(string s) {

    int num['Y'] = {0};
    int sum = 0;

    num['I'] = 1;
    num['V'] = 5;
    num['X'] = 10;
    num['L'] = 50;
    num['C'] = 100;
    num['D'] = 500;
    num['M'] = 1000;

    for (int i = 0; i < s.size() - 1; ++i) {
      if (num[s[i]] >= num[s[i + 1]]) {
        sum += num[s[i]];
      } else {
        sum -= num[s[i]];
      }
    }

    sum += num[s.back()];

    return sum;
  }
};
