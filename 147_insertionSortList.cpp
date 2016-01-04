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
  ListNode *insertionSortList(ListNode *head) {
    ListNode dummy(INT_MIN);
    dummy.next = head;

    while (head && head->next) {
      if (head->next->val >= head->val) {
        head = head->next;
      } else {
        ListNode *p = head->next;
        head->next = head->next->next;
        ListNode *i = &dummy;
        while (i->next->val < p->val)
          i = i->next;
        p->next = i->next;
        i->next = p;
      }
    }

    return dummy.next;
  }
};
