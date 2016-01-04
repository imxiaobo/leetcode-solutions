class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> all;

    for (int i = 1; i <= num.size(); ++i) {
      const auto &lhsNum = num.substr(0, i);
      const auto &remain = num.substr(i);

      auto lhs = atoll(lhsNum.c_str());

      addOperators(remain, lhsNum, target, lhs, lhs, all);

      if (lhs == 0LL)
        break;
    }

    return all;
  }

  void addOperators(const string &seq, const string &expr, long long target,
                    long long partialVal, long long lastOperand,
                    vector<string> &all) {
    // cout << seq << ' ' << expr << ' ' << target << ' ' << partialVal << ' '
    // << lastOperand << endl;
    if (seq.empty() && partialVal == target) {
      all.push_back(expr);
    }

    for (int i = 1; i <= seq.size(); ++i) {
      const auto &lhsNum = seq.substr(0, i);
      const auto &remain = seq.substr(i);

      auto lhs = atoll(lhsNum.c_str());

      addOperators(remain, expr + '+' + lhsNum, target, partialVal + lhs, lhs,
                   all);
      addOperators(remain, expr + '-' + lhsNum, target, partialVal - lhs, -lhs,
                   all);
      addOperators(remain, expr + '*' + lhsNum, target,
                   (partialVal - lastOperand) + lastOperand * lhs,
                   lastOperand * lhs, all);
      if (lhs == 0LL)
        break;
    }
  }
};
