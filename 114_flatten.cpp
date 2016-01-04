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
  void flatten(TreeNode *root) {
    TreeNode dummy(0);
    TreeNode *prev = &dummy;
    inorder(root, prev);
  }

  void inorder(TreeNode *root, TreeNode *&prev) {
    if (!root)
      return;

    auto left = root->left;
    auto right = root->right;

    prev->left = nullptr;
    prev->right = root;
    prev = prev->right;

    inorder(left, prev);
    inorder(right, prev);
  }
};
