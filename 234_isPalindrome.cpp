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
  bool isPalindrome(ListNode *head) {

    if (!head || !head->next)
      return true;

    ListNode *slow = head;
    ListNode *fast = head;

    while (true) {
      if (!fast->next || !fast->next->next)
        break;
      fast = fast->next->next;
      slow = slow->next;
    }

    fast = reverse(slow->next);
    slow = head;

    while (fast) {
      if (slow->val != fast->val)
        return false;
      slow = slow->next;
      fast = fast->next;
    }

    return true;
  }

  ListNode *reverse(ListNode *head) {
    if (!head)
      return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *t = head;

    while (t->next) {
      ListNode *tmp = t->next;

      t->next = tmp->next;
      tmp->next = dummy.next;
      dummy.next = tmp;
    }

    return dummy.next;
  }
};
