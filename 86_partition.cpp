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
  ListNode *partition(ListNode *head, int x) {
    ListNode h1(0), h2(0);
    ListNode *lt = &h1, *gte = &h2;

    while (head) {
      if (head->val < x) {
        lt->next = head;
        lt = lt->next;
      } else {
        gte->next = head;
        gte = gte->next;
      }
      head = head->next;
    }
    gte->next = nullptr;
    lt->next = h2.next;
    return h1.next;
  }
};
