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
  void recoverTree(TreeNode *root) {
    if (root) {
      TreeNode *prev = nullptr;
      pair<TreeNode *, TreeNode *> result{nullptr, nullptr};
      inorder(root, prev, result);
      if (result.first && result.second) {
        swap(result.first->val, result.second->val);
      }
    }
  }

  void inorder(TreeNode *root, TreeNode *&prev,
               pair<TreeNode *, TreeNode *> &result) {
    if (root) {
      inorder(root->left, prev, result);
      if (prev && prev->val > root->val) {
        if (!result.first && !result.second) {
          result.first = prev;
          result.second = root;
        } else {
          result.second = root;
        }
      }
      prev = root;
      inorder(root->right, prev, result);
    }
  }
};
