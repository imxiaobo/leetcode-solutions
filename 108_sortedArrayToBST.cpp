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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
  }

  TreeNode *sortedArrayToBST(vector<int> &nums, int b, int e) {

    if (b <= e) {
      int mid = b + (e - b) / 2;
      TreeNode *root = new TreeNode(nums[mid]);
      root->left = sortedArrayToBST(nums, b, mid - 1);
      root->right = sortedArrayToBST(nums, mid + 1, e);
      return root;
    }

    return nullptr;
  }
};
