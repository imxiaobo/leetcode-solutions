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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;
    ListNode *curr = prev->next;

    while (curr) {
      while (curr && curr->val == prev->next->val) {
        curr = curr->next;
      }

      if (!curr) {
        if (prev->next->next) {
          prev->next = nullptr;
        }
      } else if (curr == prev->next->next) {
        prev = prev->next;
        curr = curr->next;
      } else {
        prev->next = curr;
        curr = curr->next;
      }
    }

    return dummy.next;
  }
};
