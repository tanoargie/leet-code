/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *getNextKth(ListNode *start, int k) {
    int counter = 0;
    while (start && counter < k) {
      counter++;
      start = start->next;
    }
    return start;
  }
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *groupPrev = dummy;
    while (true) {
      ListNode *lastFromGroup = this->getNextKth(groupPrev, k);
      if (!lastFromGroup) {
        // at the end of the list there is no k elems
        return dummy->next;
      }
      ListNode *startNextGroup = lastFromGroup->next;

      // reverse from groupPrev->next to startNextGroup;
      ListNode *curr = groupPrev->next;
      ListNode *prev = lastFromGroup->next;
      while (curr != startNextGroup) {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      ListNode *tmp = groupPrev->next;
      groupPrev->next = lastFromGroup;
      groupPrev = tmp;
    }
  }
};
