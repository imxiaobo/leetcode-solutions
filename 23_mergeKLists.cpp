/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  struct cmp {
    bool operator()(ListNode *lhs, ListNode *rhs) const {
      return lhs->val > rhs->val;
    }
  };

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {

    priority_queue<ListNode *, vector<ListNode *>, cmp> minHeap;
    for (const auto &node : lists)
      if (node)
        minHeap.emplace(node);
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (!minHeap.empty()) {
      tail->next = minHeap.top();
      tail = tail->next;
      minHeap.pop();
      if (tail->next) {
        minHeap.emplace(tail->next);
      }
    }
    return dummy.next;
  }
};
