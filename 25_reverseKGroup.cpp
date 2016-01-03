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
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *p = &dummy;
    while (p)
      p = reverseK(p, k);
    return dummy.next;
  }

  ListNode *reverseK(ListNode *prev, int k) {
    // find tail
    ListNode *tail = prev->next;
    while (k && tail) {
      tail = tail->next;
      --k;
    }
    // not enough to reverse
    if (k)
      return nullptr;

    // reverse
    ListNode dummy(0);
    ListNode *next = tail;
    ListNode *p = prev->next;
    tail = prev->next;
    while (p != next) {
      ListNode *tmp = p->next;
      p->next = dummy.next;
      dummy.next = p;
      p = tmp;
    }
    tail->next = next;
    prev->next = dummy.next;
    return tail;
  }
};
