class Solution {
public:
  vector<int> grayCode(int n) {
    if (n == 0)
      return {0};
    else {
      auto result = grayCode(n - 1);
      for (int i = result.size() - 1; i >= 0; --i)
        result.push_back((1 << (n - 1)) + result[i]);
      return move(result);
    }
  }
};
