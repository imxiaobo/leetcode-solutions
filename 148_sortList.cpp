/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  ListNode *merge(ListNode *a, ListNode *b, ListNode *tail) {
    while (a && b) {
      if (a->val < b->val) {
        tail->next = a;
        a = a->next;
      } else {
        tail->next = b;
        b = b->next;
      }
      tail = tail->next;
    }

    tail->next = a ? a : b;
    while (tail->next) {
      tail = tail->next;
    }

    return tail;
  }

  int sortLen(ListNode *head) {
    int result = 0;
    while (head && head->next) {
      if (head->val > head->next->val) {
        swap(head->val, head->next->val);
      }
      head = head->next->next;
      result += 2;
    }
    if (head)
      ++result;
    return result;
  }

  ListNode *split(ListNode *head, int step) {
    while (head) {
      if (--step == 0) {
        auto next = head->next;
        head->next = nullptr;
        return next;
      }
      head = head->next;
    }
    return nullptr;
  }

public:
  ListNode *sortList(ListNode *head) {

    int length = sortLen(head);
    if (length < 2)
      return head;

    ListNode dummy(0);
    dummy.next = head;

    ListNode *tail, *current, *left, *right;
    for (int step = 2; step < length; step <<= 1) {
      tail = &dummy;
      current = dummy.next;
      while (current) {
        left = current;
        right = split(left, step);
        current = split(right, step);
        tail = merge(left, right, tail);
      }
    }

    return dummy.next;
  }
};
