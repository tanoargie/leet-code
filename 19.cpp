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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // prevN is N + 1 steps behind curr always
    int counter = 1;
    ListNode *curr = head;
    ListNode *prevN = head;
    while (curr->next) {
      if (counter > n) {
        prevN = prevN->next;
      }
      curr = curr->next;
      counter++;
    }
    if (prevN == curr) {
      head = nullptr;
    } else if (counter <= n && prevN == head) {
      head = head->next;
    } else if (prevN->next == curr && n == 1) {
      prevN->next = nullptr;
    } else {
      ListNode *oldNext = prevN->next;
      prevN->next = oldNext->next;
    }
    return head;
  }
};
