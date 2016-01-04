// Trie + dfs + bt
class TrieNode {
  bool e;
  TrieNode *children['z' - 'a' + 1];

public:
  // Initialize your data structure here.
  TrieNode() = default;

  TrieNode *create(char c) {
    if (!children[c - 'a'])
      children[c - 'a'] = new TrieNode();
    return children[c - 'a'];
  }

  TrieNode *search(char c) const { return children[c - 'a']; }

  bool exist() const { return e; }

  void mark() { e = true; }

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

  const TrieNode *getRoot() const { return root; }

  // Inserts a word into the trie.
  void insert(const string &word) {
    auto *p = root;
    for (const auto &i : word) {
      p = p->create(i);
    }
    p->mark();
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

class Solution {
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {

    if (board.empty() || board[0].empty() || words.empty())
      return {};
    int R = board.size(), C = board[0].size();

    Trie trie;
    for (const auto &word : words)
      trie.insert(word);

    unordered_set<string> found;
    string word;
    for (int row = 0; row < R; ++row) {
      for (int column = 0; column < C; ++column) {
        dfs(board, row, column, R, C, trie.getRoot(), word, found);
      }
    }

    return move(vector<string>(found.begin(), found.end()));
  }

  void dfs(vector<vector<char>> &board, int row, int column, int R, int C,
           const TrieNode *t, string &word, unordered_set<string> &found) {
    if (board[row][column] == '.')
      return;
    const char c = board[row][column];
    t = t->search(c);
    if (t) {
      board[row][column] = '.';
      word.push_back(c);

      if (t->exist())
        found.insert(word);

      if (row - 1 >= 0)
        dfs(board, row - 1, column, R, C, t, word, found);
      if (row + 1 < R)
        dfs(board, row + 1, column, R, C, t, word, found);
      if (column - 1 >= 0)
        dfs(board, row, column - 1, R, C, t, word, found);
      if (column + 1 < C)
        dfs(board, row, column + 1, R, C, t, word, found);

      word.pop_back();
      board[row][column] = c;
    }
  }
};
