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
  bool isValidBST(TreeNode *root) {
    long prev = LONG_MIN;
    return inorder(root, prev);
  }

  bool inorder(TreeNode *root, long &prev) {
    if (!root)
      return true;

    if (root->left) {
      if (!inorder(root->left, prev))
        return false;
    }

    if (prev >= root->val)
      return false;
    prev = root->val;

    if (root->right) {
      if (!inorder(root->right, prev))
        return false;
    }

    return true;
  }
};
