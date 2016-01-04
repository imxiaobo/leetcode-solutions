class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     unordered_set<string> &wordList) {

    if (beginWord == endWord)
      return {{endWord}};

    unordered_map<string, vector<string>> graph;
    vector<vector<string>> paths;
    unordered_set<string> forward{beginWord};
    unordered_set<string> backward{endWord};

    if (buildGraphBDS(forward, backward, wordList, graph, true)) {
      vector<string> path;
      getPathsDFS(beginWord, endWord, graph, path, paths);
    }

    return paths;
  }

  bool buildGraphBDS(unordered_set<string> &forward,
                     unordered_set<string> &backward,
                     unordered_set<string> &wordList,
                     unordered_map<string, vector<string>> &graph,
                     bool forwardDirection) {
    if (forward.size() > backward.size()) {
      swap(forward, backward);
      forwardDirection = !forwardDirection;
    }

    if (forward.empty())
      return false;

    for (const auto &w : forward)
      wordList.erase(w);
    for (const auto &w : backward)
      wordList.erase(w);

    unordered_set<string> next;
    bool connect = false;

    for (const string &word : forward) {
      string nextWord(word);
      for (int idx = 0; idx < nextWord.size(); ++idx) {
        char original = nextWord[idx];
        for (char c = 'a'; c <= 'z'; ++c) {
          nextWord[idx] = c;
          if (backward.find(nextWord) != backward.end()) {
            connect = true;
            forwardDirection ? graph[word].push_back(nextWord)
                             : graph[nextWord].push_back(word);
          } else if (!connect && wordList.find(nextWord) != wordList.end()) {
            next.insert(nextWord);
            forwardDirection ? graph[word].push_back(nextWord)
                             : graph[nextWord].push_back(word);
          }
        }
        nextWord[idx] = original;
      }
    }

    swap(forward, next);

    return connect ||
           buildGraphBDS(forward, backward, wordList, graph, forwardDirection);
  }

  void getPathsDFS(const string &beginWord, const string &endWord,
                   unordered_map<string, vector<string>> &graph,
                   vector<string> &path, vector<vector<string>> &allPaths) {
    path.push_back(beginWord);
    if (beginWord == endWord)
      allPaths.push_back(path);
    else {
      for (const auto &v : graph[beginWord])
        getPathsDFS(v, endWord, graph, path, allPaths);
    }
    path.pop_back();
  }
};
