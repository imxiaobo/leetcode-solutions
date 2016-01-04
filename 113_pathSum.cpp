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
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    if (!root)
      return {};
    vector<vector<int>> result;
    vector<int> path;
    dfs(root, 0, sum, path, result);
    return move(result);
  }

  void dfs(TreeNode *root, int pathSum, int sum, vector<int> &path,
           vector<vector<int>> &result) {
    path.push_back(root->val);
    pathSum += root->val;
    if (!root->left && !root->right) {
      if (sum == pathSum) {
        result.emplace_back(path);
      }
    } else {
      if (root->left)
        dfs(root->left, pathSum, sum, path, result);
      if (root->right)
        dfs(root->right, pathSum, sum, path, result);
    }
    path.pop_back();
  }
};
