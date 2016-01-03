class Solution {
public:
  string countAndSay(int n) {

    string result("1");
    while (n - 1 != 0) {
      result = move(next(result));
      --n;
    }
    return result;
  }

  string next(const string &s) {
    auto it = s.begin();
    while (it != s.end() && *it == s.front())
      ++it;

    int count = it - s.begin();

    if (it == s.end()) {
      return move(to_string(count) + s.front());
    } else {
      return move(to_string(count) + s.front() + next(string(it, s.end())));
    }
  }
};
