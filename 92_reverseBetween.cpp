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
  ListNode *reverseBetween(ListNode *head, int m, int n) {

    if (m == n)
      return head;

    ListNode dummy(0);
    dummy.next = head;

    ListNode *hp = &dummy;
    ListNode *h = dummy.next;
    ListNode *t = dummy.next;

    while (m - 1) {
      h = h->next;
      hp = hp->next;
      --m;
    }

    while (n - 1) {
      t = t->next;
      --n;
    }

    while (true) {
      bool shouldBreak = false;

      if (h->next == t)
        shouldBreak = true;

      ListNode *tmp = hp->next;

      hp->next = h->next;
      h->next = hp->next->next;
      hp->next->next = tmp;

      if (shouldBreak)
        break;
    }

    return dummy.next;
  }
};
