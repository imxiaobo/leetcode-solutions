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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {

    // node, level
    queue<pair<TreeNode *, int>> q;
    vector<vector<int>> result;

    if (!root)
      return result;

    q.emplace(root, 0);

    while (!q.empty()) {
      auto pair = q.front();
      TreeNode *t = pair.first;
      int level = pair.second;
      q.pop();

      if (level + 1 > result.size())
        result.resize(level + 1);

      result[level].push_back(t->val);
      if (t->left)
        q.emplace(t->left, level + 1);
      if (t->right)
        q.emplace(t->right, level + 1);
    }

    reverse(result.begin(), result.end());

    return result;
  }
};
