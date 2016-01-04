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
  int countNodes(TreeNode *root) { return countNodes(root, leftHeight(root)); }

  int countNodes(TreeNode *root, int lh) {
    if (lh == rightHeight(root))
      return (1 << lh) - 1;
    else
      return 1 + countNodes(root->left, lh - 1) + countNodes(root->right);
  }

  int leftHeight(TreeNode *root) {
    int h = 0;
    while (root) {
      ++h;
      root = root->left;
    }
    return h;
  }

  int rightHeight(TreeNode *root) {
    int h = 0;
    while (root) {
      ++h;
      root = root->right;
    }
    return h;
  }
};
