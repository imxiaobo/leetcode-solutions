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
  int kthSmallest(TreeNode *root, int k) {
    int traversal;
    inorder(root, traversal, k);
    return traversal;
  }

  void inorder(TreeNode *root, int &traversal, int &k) {
    if (root) {
      if (root->left)
        inorder(root->left, traversal, k);

      if (k == 0)
        return;
      traversal = root->val;
      --k;

      if (root->right)
        inorder(root->right, traversal, k);
    }
  }
};
