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
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) {
      return head;
    }
    ListNode *curr = head;
    int val = curr->val;
    ListNode *prev = nullptr;
    while (curr && curr->next) {
      if (curr->next->val > val) {
        if (!prev) {
          head = curr;
        } else {
          prev->next = curr;
        }
        prev = curr;
        val = curr->next->val;
        curr = curr->next;
      } else {
        while (curr->next && curr->next->val == val) {
          curr = curr->next;
        }
        if (curr && curr->next && curr->next->val != val) {
          val = curr->next->val;
          curr = curr->next;
        } else if (!curr->next) {
          curr = nullptr;
        }
      }
    }
    if (prev) {
      prev->next = curr;
    } else {
      if (!curr) {
        return nullptr;
      } else {
        head = curr;
      }
    }

    return head;
  }
};
