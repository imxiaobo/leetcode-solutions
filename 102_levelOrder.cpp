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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    queue<pair<TreeNode *, int>> q;
    if (root)
      q.emplace(root, 0);
    while (!q.empty()) {
      pair<TreeNode *, int> p = move(q.front());
      q.pop();
      TreeNode *t = p.first;
      int level = p.second;
      if (level == result.size()) {
        result.resize(level + 1);
      }
      result[level].push_back(t->val);
      if (t->left)
        q.emplace(t->left, level + 1);
      if (t->right)
        q.emplace(t->right, level + 1);
    }
    return move(result);
  }
};
