class Solution {
public:
  int ladderLength(string beginWord, string endWord,
                   unordered_set<string> &wordList) {
    queue<pair<string, int>> q;
    q.emplace(beginWord, 1);
    wordList.erase(beginWord);
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      if (p.first == endWord)
        return p.second;
      addNextWords(p.first, p.second + 1, wordList, q);
    }
    return 0;
  }

  void addNextWords(string &word, int distance, unordered_set<string> &wordList,
                    queue<pair<string, int>> &q) {
    for (int i = 0; i < word.size(); ++i) {
      char letter = word[i];
      for (char c = 'a'; c <= 'z'; ++c) {
        if (word[i] != c) {
          word[i] = c;
          if (wordList.find(word) != wordList.end()) {
            q.emplace(word, distance);
            wordList.erase(word);
          }
        }
      }
      word[i] = letter;
    }
  }
};
