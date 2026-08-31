/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head) {
      return nullptr;
    }
    Node *newHead = new Node(head->val);
    newHead->random = head->random;
    Node *curr = head;
    Node *currCopy = newHead;
    // map old node -> new node
    unordered_map<Node *, Node *> oldPositions({{head, newHead}});
    while (curr->next) {
      curr = curr->next;
      Node *newNode = new Node(curr->val);
      newNode->next = curr->next;
      newNode->random = curr->random;
      currCopy->next = newNode;
      currCopy = newNode;
      oldPositions[curr] = newNode;
    }
    curr = newHead;
    if (curr->random) {
      curr->random = oldPositions[curr->random];
    }
    while (curr->next) {
      curr = curr->next;
      if (curr->random) {
        curr->random = oldPositions[curr->random];
      }
    }

    return newHead;
  }
};
