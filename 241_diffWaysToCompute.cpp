class Solution {
public:
  vector<int> diffWaysToCompute(string input) {

    int size = input.size();
    vector<vector<vector<int>>> memo(size, vector<vector<int>>(size));
    return diffWaysToCompute(input, 0, size - 1, memo);
  }

  const vector<int> &diffWaysToCompute(const string &input, int from, int to,
                                       vector<vector<vector<int>>> &memo) {
    auto &result = memo[from][to];

    if (!result.empty())
      return result;

    for (int idx = from + 1; idx < to; ++idx) {
      if (input[idx] == '+' || input[idx] == '-' || input[idx] == '*') {
        for (int left : diffWaysToCompute(input, from, idx - 1, memo)) {
          for (int right : diffWaysToCompute(input, idx + 1, to, memo)) {
            switch (input[idx]) {
            case '*':
              result.push_back(left * right);
              break;
            case '+':
              result.push_back(left + right);
              break;
            case '-':
              result.push_back(left - right);
              break;
            }
          }
        }
      }
    }

    if (result.empty()) {
      result.push_back(atoi(input.substr(from, to - from + 1).c_str()));
    }

    return result;
  }
};
