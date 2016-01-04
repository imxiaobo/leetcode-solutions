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
  int maxPathSum(TreeNode *root) {
    int result = INT_MIN;
    maxPathSum(root, result);
    return result;
  }

  int maxPathSum(TreeNode *root, int &result) {
    if (!root)
      return 0;
    int left = maxPathSum(root->left, result);
    int right = maxPathSum(root->right, result);
    result = max(result, root->val + left + right);
    return max(0, root->val + max(left, right));
  }
};
