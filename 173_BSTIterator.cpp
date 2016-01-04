/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    TreeNode *t = root;
    while (t) {
      level.push(t);
      t = t->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {

    if (level.size() == 0)
      return false;
    return true;
  }

  /** @return the next smallest number */
  int next() {
    TreeNode *t = level.top();

    level.pop();

    if (t->right) {
      TreeNode *p = t->right;

      while (p) {
        level.push(p);
        p = p->left;
      }
    }

    return t->val;
  }

private:
  std::stack<TreeNode *> level;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
