class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {

    unordered_map<string, multiset<string>> anagrams;

    for (const auto &s : strs) {
      auto k = s;
      sort(k.begin(), k.end());
      anagrams[k].insert(s);
    }

    vector<vector<string>> anagramGroups;

    for (const auto &p : anagrams) {
      anagramGroups.emplace_back(p.second.begin(), p.second.end());
    }

    return move(anagramGroups);
  }
};
