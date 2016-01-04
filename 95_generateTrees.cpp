/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0)
      return {};
    vector<vector<vector<TreeNode *>>> memo(n + 2,
                                            vector<vector<TreeNode *>>(n + 2));
    return move(generateTrees(1, n, memo));
  }

  vector<TreeNode *> &generateTrees(int from, int to,
                                    vector<vector<vector<TreeNode *>>> &memo) {
    auto &m = memo[from][to];
    if (m.empty()) {
      if (from > to) {
        m.emplace_back(nullptr);
      } else {
        for (int root = from; root <= to; ++root) {
          for (auto left : generateTrees(from, root - 1, memo)) {
            for (auto right : generateTrees(root + 1, to, memo)) {
              TreeNode *t = new TreeNode(root);
              t->left = left;
              t->right = right;
              m.emplace_back(t);
            }
          }
        }
      }
    }
    return m;
  }
};
