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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1);
  }

  TreeNode *buildTree(vector<int> &p, int pb, int pe, vector<int> &i, int ib,
                      int ie) {

    if (pb > pe || ib > ie)
      return NULL;

    int rootVal = p[pb];
    int x = pb + 1, y = ib;

    while (i[y] != rootVal) {
      x++, y++;
    }

    TreeNode *root = new TreeNode(rootVal);
    root->left = buildTree(p, pb + 1, x - 1, i, ib, y - 1);
    root->right = buildTree(p, x, pe, i, y + 1, ie);

    return root;
  }
};
