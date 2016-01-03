/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*

 Given a list, rotate the list to the right by k places, where k is
non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
 */

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;
    ListNode *curr = dummy.next;
    ListNode *tail;
    int length = len(head, tail);
    if (length <= 1)
      return head;

    // shift right
    k = k % length;
    // shift left
    int shiftLeft = (length - k) % length;
    if (shiftLeft == 0)
      return head;

    while (shiftLeft) {
      curr = curr->next;
      prev = prev->next;
      --shiftLeft;
    }

    dummy.next = curr;
    tail->next = head;
    prev->next = nullptr;

    return dummy.next;
  }

  int len(ListNode *head, ListNode *&tail) {
    int l = 0;
    while (head) {
      if (!head->next)
        tail = head;
      head = head->next;
      ++l;
    }
    return l;
  }
};
