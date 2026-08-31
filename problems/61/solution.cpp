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
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || k == 0) {
      return head;
    }
    int counter = 1;
    ListNode *curr = head;
    while (curr->next) {
      counter++;
      curr = curr->next;
    }
    if (counter == 1) {
      return head;
    }
    k = k % counter;
    if (k == 0) {
      return head;
    }
    curr = head;
    ListNode *prev = nullptr;
    counter = 0;
    while (curr->next) {
      counter++;
      if (counter >= k) {
        if (!prev) {
          prev = head;
        } else {
          prev = prev->next;
        }
      }
      curr = curr->next;
    }
    // here prev points to new tail
    if (prev) {
      ListNode *newHead = prev->next;
      curr->next = head;
      head = newHead;
      prev->next = nullptr;
    }

    return head;
  }
};
