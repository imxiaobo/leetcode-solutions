class Solution {
public:
  int maxProduct(vector<string> &words) {

    if (words.empty())
      return 0;

    vector<std::bitset<26>> vec(words.size());
    for (int w = 0; w < words.size(); ++w) {
      for (char c : words[w]) {
        vec[w].set(c - 'a', true);
      }
    }

    int result = 0;
    for (int i = 0; i < words.size() - 1; ++i) {
      for (int j = i + 1; j < words.size(); ++j) {
        if ((vec[i] & vec[j]).none()) {
          result = max((int)(words[i].size() * words[j].size()), result);
        }
      }
    }
    return result;
  }
};
