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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    if (!headA || !headB)
      return nullptr;

    ListNode *tailA = headA;
    ListNode *tailB = headB;

    int lenA = (headA != nullptr);
    int lenB = (headB != nullptr);

    while (tailA) {

      if (tailA->next) {
        ++lenA;
        tailA = tailA->next;
      } else
        break;
    }

    while (tailB) {

      if (tailB->next) {
        ++lenB;
        tailB = tailB->next;
      } else
        break;
    }

    if (tailA != tailB)
      return nullptr;

    ListNode *longList = headA, *shortList = headB;

    if (lenA < lenB) {
      swap(longList, shortList);
    }

    int lenDiff = abs(lenA - lenB);

    while (lenDiff != 0) {
      longList = longList->next;
      --lenDiff;
    }

    while (longList != shortList) {
      longList = longList->next;
      shortList = shortList->next;
    }

    return longList;
  }
};
