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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode *prev = &dummy;
    ListNode *tail = &dummy;

    while (n) {
      tail = tail->next;
      --n;
    }

    while (tail->next) {
      tail = tail->next;
      prev = prev->next;
    }

    prev->next = prev->next->next;
    return dummy.next;
  }
};
