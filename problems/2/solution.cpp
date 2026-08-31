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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int rest = 0;
    int partial = l1->val + l2->val + rest;
    if (partial >= 10) {
      rest++;
      partial -= 10;
    }
    ListNode *head = new ListNode(partial);
    ListNode *curr = head;

    while (l1->next && l2->next) {
      l1 = l1->next;
      l2 = l2->next;
      partial = l1->val + l2->val + rest;
      if (partial >= 10) {
        rest = 1;
        partial -= 10;
      } else {
        rest = 0;
      }
      ListNode *nx = new ListNode(partial);
      curr->next = nx;
      curr = nx;
    }
    while (l1->next) {
      l1 = l1->next;
      partial = l1->val + rest;
      if (partial >= 10) {
        rest = 1;
        partial -= 10;
      } else {
        rest = 0;
      }
      ListNode *nx = new ListNode(partial);
      curr->next = nx;
      curr = nx;
    }
    while (l2->next) {
      l2 = l2->next;
      partial = l2->val + rest;
      if (partial >= 10) {
        rest = 1;
        partial -= 10;
      } else {
        rest = 0;
      }
      ListNode *nx = new ListNode(partial);
      curr->next = nx;
      curr = nx;
    }
    if (rest > 0) {
      ListNode *nx = new ListNode(rest);
      curr->next = nx;
      curr = nx;
    }

    return head;
  }
};
