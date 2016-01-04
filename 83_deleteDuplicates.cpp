/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {

    if (head) {
      ListNode *slow = head, *fast = slow->next;

      while (fast) {
        if (fast->val != slow->val) {
          slow = slow->next;
          slow->val = fast->val;
        } else {
          fast = fast->next;
        }
      }

      slow->next = nullptr;
    }

    return head;
  }
};
