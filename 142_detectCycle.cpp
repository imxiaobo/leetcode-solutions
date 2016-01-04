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
  ListNode *detectCycle(ListNode *head) {

    ListNode *slow = head;
    ListNode *fast = head;

    while (true) {
      if (!fast || !fast->next || !fast->next->next)
        return nullptr;
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast)
        break;
    }

    fast = head;
    while (true) {
      if (fast == slow)
        return fast;
      fast = fast->next;
      slow = slow->next;
    }
  }
};
