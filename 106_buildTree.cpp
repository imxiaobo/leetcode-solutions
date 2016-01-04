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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return buildTree(inorder, 0, inorder.size() - 1, postorder, 0,
                     postorder.size() - 1);
  }

  TreeNode *buildTree(vector<int> &i, int ib, int ie, vector<int> &p, int pb,
                      int pe) {

    if (ib > ie)
      return NULL;

    int rootVal = p[pe];
    int x = ib, y = pb;

    while (x < ie) {
      if (i[x] == rootVal)
        break;
      ++x, ++y;
    }

    TreeNode *root = new TreeNode(rootVal);

    root->left = buildTree(i, ib, x - 1, p, pb, y - 1);

    root->right = buildTree(i, x + 1, ie, p, y, pe - 1);

    return root;
  }
};
