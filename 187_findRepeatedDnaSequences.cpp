class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {

    if (s.size() < 11)
      return {};

    unordered_map<string, int> m;
    vector<string> results;
    for (int start = 0; start <= s.size() - 10; ++start) {
      auto seq = s.substr(start, 10);
      if (++m[seq] == 2)
        results.emplace_back(move(seq));
    }

    return move(results);
  }
};
