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
    while (head->next) {
      if (head->val == INT_MIN) {
        return true;
      }
      head->val = INT_MIN;
      head = head->next;
    }

    return res;
  }
};
