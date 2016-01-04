class TrieNode {
  int count = 0;
  TrieNode *children['z' - 'a' + 1] = {nullptr};

public:
  // Initialize your data structure here.
  TrieNode() = default;

  TrieNode *create(char c) {
    if (!children[c - 'a'])
      children[c - 'a'] = new TrieNode();
    return children[c - 'a'];
  }

  TrieNode *search(char c) const { return children[c - 'a']; }

  bool exist() const { return count > 0; }

  void mark() { ++count; }

  ~TrieNode() {
    for (auto *t : children) {
      if (t) {
        delete t;
        t = nullptr;
      }
    }
  }
};

class Trie {
public:
  Trie() : root(new TrieNode()) {}

  // Inserts a word into the trie.
  void insert(const string &word) {
    auto *p = root;
    for (const auto &i : word) {
      p = p->create(i);
    }
    p->mark();
  }

  // Returns if the word is in the trie.
  bool search(const string &word) const {

    const auto *p = root;
    for (const auto &i : word) {
      p = p->search(i);
      if (!p)
        return false;
    }
    return p->exist();
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(const string &prefix) const {
    const auto *p = root;
    for (const auto &i : prefix) {
      p = p->search(i);
      if (!p)
        return false;
    }
    return true;
  }

  ~Trie() {
    if (root) {
      delete root;
      root = nullptr;
    }
  }

private:
  TrieNode *root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
