/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {

    RandomListNode dummy(0);
    dummy.next = head;

    // make copy (interleaving with original one)
    while (head) {
      auto *next = head->next;
      auto *copy = new RandomListNode(head->label);
      copy->next = next;
      head->next = copy;
      head = next;
    }

    // fix random
    head = dummy.next;
    while (head) {
      auto *copy = head->next;
      if (head->random)
        copy->random = head->random->next;
      head = head->next->next;
    }

    // extract copy
    head = dummy.next;
    RandomListNode result(0);
    RandomListNode *tail = &result;
    while (head) {
      tail->next = head->next;
      tail = tail->next;

      head->next = head->next->next;
      head = head->next;
    }

    return result.next;
  }
};
