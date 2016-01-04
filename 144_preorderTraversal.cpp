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
  vector<int> preorderTraversal(TreeNode *root) {
    std::stack<TreeNode *> stack;
    std::vector<int> preorder;
    if (root) {
      stack.push(root);
      while (!stack.empty()) {
        TreeNode *t = stack.top();
        stack.pop();
        if (t->right)
          stack.push(t->right);
        if (t->left)
          stack.push(t->left);
        preorder.push_back(t->val);
      }
    }
    return preorder;
  }
};
