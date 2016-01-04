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
  void reorderList(ListNode *head) {

    if (!head || !head->next || !head->next->next)
      return;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    fast = reverse(slow->next);
    slow->next = nullptr;
    merge(head, fast);
  }

  ListNode *reverse(ListNode *head) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode *p = head;

    while (p->next) {
      ListNode *tmp = dummy.next;
      dummy.next = p->next;
      p->next = p->next->next;
      dummy.next->next = tmp;
    }

    return dummy.next;
  }

  ListNode *merge(ListNode *first, ListNode *second) {
    ListNode dummy(0);
    ListNode *p = &dummy;

    while (first && second) {
      p->next = first;
      p = p->next;
      first = first->next;

      p->next = second;
      p = p->next;
      second = second->next;
    }

    if (second) {
      p->next = second;
    } else if (first) {
      p->next = first;
    } else
      p->next = nullptr;

    return dummy.next;
  }
};
