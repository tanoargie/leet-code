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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *curr1 = list1;
    ListNode *curr2 = list2;
    ListNode *head = nullptr;
    if (!curr1 && !curr2) {
      return head;
    }
    ListNode *curr;

    while (curr1 || curr2) {
      ListNode *newNode = new ListNode();
      if (curr1 && curr2 && curr1->val > curr2->val) {
        newNode->val = curr2->val;
        curr2 = curr2->next;
      } else if (curr1 && curr2) {
        newNode->val = curr1->val;
        curr1 = curr1->next;
      } else if (curr1) {
        newNode->val = curr1->val;
        curr1 = curr1->next;
      } else if (curr2) {
        newNode->val = curr2->val;
        curr2 = curr2->next;
      }
      if (!head) {
        head = newNode;
        curr = head;
      } else {
        curr->next = newNode;
        curr = newNode;
      }
    }

    return head;
  }
};
