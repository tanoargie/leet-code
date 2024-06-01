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
  bool hasCycle(ListNode *head) {
    bool res = false;
    if (head == nullptr) {
      return res;
    }
    ListNode *node = head;
    while (node->next) {
      if (node->val == INT_MIN) {
        return true;
      }
      node->val = INT_MIN;
      node = node->next;
    }

    return res;
  }
};
