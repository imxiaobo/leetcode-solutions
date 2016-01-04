class TrieNode {
  bool _exist;
  unordered_map<char, TrieNode *> _children;

public:
  TrieNode() = default;
  ~TrieNode() {
    for (auto &kv : _children) {
      delete kv.second;
    }
  }

  bool exist() const { return _exist; }

  void mark() { _exist = true; }

  TrieNode *create(char c) {
    TrieNode *&t = _children[c];
    if (!t) {
      t = new TrieNode();
    }
    return t;
  }

  TrieNode *search(char c) const {
    auto it = _children.find(c);
    if (it == _children.end())
      return nullptr;
    return it->second;
  }

  const unordered_map<char, TrieNode *> &children() const { return _children; }
};

class WordDictionary {
  TrieNode *const root;

  bool search(const string &word, int idx, TrieNode *t) {

    if (idx == word.size() - 1) {
      if (word[idx] == '.') {
        for (const auto &kv : t->children()) {
          if (kv.second->exist())
            return true;
        }
        return false;
      } else {
        t = t->search(word[idx]);
        return t && t->exist();
      }
    }

    if (word[idx] != '.') {
      t = t->search(word[idx]);
      if (!t)
        return false;
      return search(word, idx + 1, t);
    } else {
      for (const auto &kv : t->children()) {
        if (search(word, idx + 1, kv.second)) {
          return true;
        }
      }
      return false;
    }
  }

public:
  WordDictionary() : root(new TrieNode()) {}

  // Adds a word into the data structure.
  void addWord(string word) {
    TrieNode *p = root;
    for (char c : word) {
      p = p->create(c);
    }
    p->mark();
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) { return search(word, 0, root); }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
