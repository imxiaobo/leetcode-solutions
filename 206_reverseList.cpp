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
  ListNode *reverseList(ListNode *head) {
    ListNode dummy(0);
    while (head) {
      ListNode *next = head->next;
      head->next = dummy.next;
      dummy.next = head;
      head = next;
    }
    return dummy.next;
  }
};
