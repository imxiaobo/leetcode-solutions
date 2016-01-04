class Solution {
public:
  int longestConsecutive(vector<int> &nums) {

    unordered_set<int> s;

    for (auto i : nums) {
      s.insert(i);
    }

    int m = 0;
    for (auto i : nums) {
      int count = 0;
      int n = i;
      while (s.find(n) != s.end()) {
        s.erase(n);
        ++count;
        ++n;
      }
      n = i - 1;
      while (s.find(n) != s.end()) {
        s.erase(n);
        ++count;
        --n;
      }
      m = max(m, count);
    }

    return m;
  }
};
