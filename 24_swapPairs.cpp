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
  ListNode *swapPairs(ListNode *head) {

    if (!head || !head->next)
      return head;

    ListNode dummy(0);

    dummy.next = head;

    ListNode *prev = &dummy;
    ListNode *curr = head;
    ListNode *next = head->next;

    while (true) {
      // swap curr and next
      curr->next = next->next;
      next->next = curr;
      prev->next = next;

      // swap pointer so prev->curr->next
      swap(curr, next);

      if (!next->next || !next->next->next)
        break;

      // advance by 2
      next = next->next->next;
      curr = curr->next->next;
      prev = prev->next->next;
    }

    return dummy.next;
  }
};
