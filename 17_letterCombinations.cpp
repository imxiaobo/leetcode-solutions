class Solution {
public:
  vector<string> letterCombinations(string digits) {

    vector<vector<char>> m = {{},
                              {},
                              {'a', 'b', 'c'},
                              {'d', 'e', 'f'},
                              {'g', 'h', 'i'},
                              {'j', 'k', 'l'},
                              {'m', 'n', 'o'},
                              {'p', 'q', 'r', 's'},
                              {'t', 'u', 'v'},
                              {'w', 'x', 'y', 'z'}};

    if (digits.empty())
      return {};
    return letterCombinations(digits, m);
  }

  vector<string> letterCombinations(string digits, vector<vector<char>> &m) {
    // cout << digits << endl;
    if (digits.size() == 1) {
      vector<string> result;
      for (const auto &c : m[digits[0] - '0']) {
        // cout << c << endl;
        result.emplace_back(1, c);
      }
      return move(result);
    } else {
      vector<string> result;
      for (const auto &s : letterCombinations(digits.substr(1), m)) {
        // cout << s << endl;
        for (const auto &c : m[digits[0] - '0']) {
          // cout << "!" << endl;
          result.emplace_back(string(1, c) + s);
        }
      }
      return move(result);
    }
  }
};
