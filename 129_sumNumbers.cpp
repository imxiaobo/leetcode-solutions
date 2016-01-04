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
  int sumNumbers(TreeNode *root) {
    int pathSum = 0;
    dfs(root, 0, pathSum);
    return pathSum;
  }

  void dfs(TreeNode *root, int path, int &pathSum) {
    if (root) {
      path = path * 10 + root->val;
      if (!root->left && !root->right) {
        pathSum += path;
      }
      dfs(root->left, path, pathSum);
      dfs(root->right, path, pathSum);
    }
  }
};
