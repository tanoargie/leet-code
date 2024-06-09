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
  ListNode *partition(ListNode *head, int x) {
    if (!head) {
      return head;
    }
    ListNode *curr = head;
    ListNode *first = nullptr;
    ListNode *second = nullptr;
    ListNode *start1 = nullptr;
    ListNode *start2 = nullptr;
    if (head->val < x) {
      first = head;
      start1 = first;
    } else {
      second = head;
      start2 = second;
    }
    while (curr->next) {
      curr = curr->next;
      if (curr->val < x) {
        if (first) {
          first->next = curr;
          first = first->next;
        } else {
          first = curr;
          start1 = first;
        }
      } else {
        if (second) {
          second->next = curr;
          second = second->next;
        } else {
          second = curr;
          start2 = second;
        }
      }
    }
    if (second) {
      second->next = nullptr;
    }
    if (first) {
      // join first with second
      first->next = start2;
    } else {
      if (start2) {
        // all elems >= x
        start1 = start2;
      }
    }

    return start1;
  }
};
