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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> view;
    queue<pair<TreeNode *, int>> q;

    if (root)
      q.emplace(root, 0);
    while (!q.empty()) {
      pair<TreeNode *, int> p = move(q.front());
      q.pop();

      if (q.empty() || p.second < q.front().second) {
        view.emplace_back(p.first->val);
      }

      if (p.first->left)
        q.emplace(p.first->left, p.second + 1);
      if (p.first->right)
        q.emplace(p.first->right, p.second + 1);
    }
    return move(view);
  }
};
