/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
  TreeNode *sortedListToBST(ListNode *head) {
    return sortedListToBST(head, length(head));
  }

  TreeNode *sortedListToBST(ListNode *&head, int len) {
    TreeNode *root = nullptr;
    if (len) {
      auto left = sortedListToBST(head, len / 2);

      root = new TreeNode(head->val);
      head = head->next;

      auto right = sortedListToBST(head, len - len / 2 - 1);

      root->left = left;
      root->right = right;
    }
    return root;
  }

  int length(ListNode *head) {
    int result = 0;
    while (head) {
      head = head->next;
      ++result;
    }
    return result;
  }
};
