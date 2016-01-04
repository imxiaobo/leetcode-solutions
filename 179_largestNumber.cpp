class Solution {
public:
  string largestNumber(vector<int> &nums) {
    if (nums.empty())
      return "";
    vector<string> snums;
    for (int n : nums)
      snums.emplace_back(to_string(n));
    sort(snums.begin(), snums.end(), [](const string &lhs, const string &rhs) {
      return lhs + rhs > rhs + lhs;
    });
    if (snums.front() == "0")
      return snums.front();
    stringstream ss;
    for (auto sn : snums)
      ss << sn;
    return move(ss.str());
  }
};
