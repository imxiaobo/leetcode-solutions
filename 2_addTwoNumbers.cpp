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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    ListNode dummy(0);
    ListNode *next = &dummy;

    int carry = 0, sum = 0;

    while (true) {
      if (l1 && l2) {
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        sum %= 10;

        next->next = new ListNode(sum);
        next = next->next;
        l1 = l1->next;
        l2 = l2->next;
      } else {
        if (!l2)
          swap(l1, l2);
        if (!l1) {
          while (l2) {
            sum = l2->val + carry;
            carry = sum / 10;
            sum %= 10;

            next->next = new ListNode(sum);
            next = next->next;
            l2 = l2->next;
          }
        }
      }

      if (!l1 && !l2)
        break;
    }

    if (carry != 0)
      next->next = new ListNode(carry);

    return dummy.next;
  }
};
