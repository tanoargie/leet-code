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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right) {
      return head;
    }
    int currPosition = 1;
    ListNode *curr = head;
    ListNode *previous = nullptr;
    while (currPosition < left) {
      currPosition++;
      previous = curr;
      curr = curr->next;
    }

    ListNode *rtail = curr;
    ListNode *rhead = nullptr;
    while (currPosition <= right) {
      ListNode *next = curr->next;
      curr->next = rhead;
      rhead = curr;
      curr = next;
      currPosition++;
    }

    if (previous) {
      previous->next = rhead;
    } else {
      head = rhead;
    }
    rtail->next = curr;

    return head;
  }
};
