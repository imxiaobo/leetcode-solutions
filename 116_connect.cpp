/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
  void connect(TreeLinkNode *root) {

    while (root) {

      TreeLinkNode *current = root;
      TreeLinkNode *p = nullptr;
      while (current) {
        // connect left
        if (current->left) {
          if (p)
            p->next = current->left;
          p = current->left;
        }
        // connect right
        if (current->right) {
          if (p)
            p->next = current->right;
          p = current->right;
        }
        current = current->next;
      }

      // next level
      while (!root->left && !root->right) {
        root = root->next;
        if (!root)
          return;
      }

      if (root->left)
        root = root->left;
      else if (root->right)
        root = root->right;
      else
        return;
    }
  }
};
