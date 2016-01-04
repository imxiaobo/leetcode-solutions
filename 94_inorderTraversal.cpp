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
  vector<int> inorderTraversal(TreeNode *root) {

    std::stack<TreeNode *> stack;
    std::vector<int> inorder;

    if (root) {
      stack.push(root);
      while (root->left) {
        stack.push(root->left);
        root = root->left;
      }

      while (!stack.empty()) {
        TreeNode *t = stack.top();
        stack.pop();
        inorder.push_back(t->val);
        if (t->right) {
          stack.push(t->right);
          t = t->right;
          while (t->left) {
            stack.push(t->left);
            t = t->left;
          }
        }
      }
    }
    return inorder;
  }
};
