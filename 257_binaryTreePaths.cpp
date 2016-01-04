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
  vector<string> binaryTreePaths(TreeNode *root) {

    vector<string> paths;

    if (root) {
      binaryTreePaths(root, std::to_string(root->val), paths);
    }

    return paths;
  }

  void binaryTreePaths(TreeNode *root, std::string path,
                       vector<string> &paths) {
    if (root) {
      if (!root->left && !root->right) {
        paths.push_back(path);
      }

      if (root->left) {
        binaryTreePaths(root->left,
                        path + "->" + std::to_string(root->left->val), paths);
      }

      if (root->right) {
        binaryTreePaths(root->right,
                        path + "->" + std::to_string(root->right->val), paths);
      }
    }
  }
};
