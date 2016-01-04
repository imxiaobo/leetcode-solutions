class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> s;
    while (true) {
      if (n == 1)
        return true;
      n = calc(n);
      if (s.find(n) != s.end())
        return false;
      else
        s.insert(n);
    }
  }

  int calc(int n) {
    int result = 0;
    while (n) {
      int mod = n % 10;
      n /= 10;
      result += mod * mod;
    }
    return result;
  }
};
