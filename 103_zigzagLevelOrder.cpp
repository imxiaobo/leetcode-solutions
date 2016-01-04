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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {

    if (!root)
      return {};

    vector<vector<int>> result;
    queue<pair<TreeNode *, int>> q;

    q.emplace(root, 0);
    while (!q.empty()) {
      deque<TreeNode *> dq;
      int level = q.front().second;
      while (!q.empty() && q.front().second == level) {
        dq.push_back(q.front().first);
        q.pop();
      }

      result.resize(level + 1);

      if (level % 2 != 0) {
        for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
          result[level].push_back((*it)->val);
        }
      } else {
        for (auto it = dq.begin(); it != dq.end(); ++it) {
          result[level].push_back((*it)->val);
        }
      }

      while (!dq.empty()) {
        TreeNode *t = dq.front();
        dq.pop_front();
        if (t->left)
          q.emplace(t->left, level + 1);
        if (t->right)
          q.emplace(t->right, level + 1);
      }
    }

    return result;
  }
};
