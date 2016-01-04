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
  vector<int> postorderTraversal(TreeNode *root) {
    stack<std::pair<TreeNode *, int>> stack;
    vector<int> postorder;

    if (root) {
      stack.push(std::make_pair(root, 0));

      while (!stack.empty()) {
        std::pair<TreeNode *, int> &t = stack.top();
        if (!t.first) {
          stack.pop();
        } else if (t.second == 0) {
          ++t.second;
          stack.push(std::make_pair(t.first->left, 0));
        } else if (t.second == 1) {
          ++t.second;
          stack.push(std::make_pair(t.first->right, 0));
        } else if (t.second == 2) {
          postorder.push_back(t.first->val);
          stack.pop();
        }
      }
    }

    return postorder;
  }
};
