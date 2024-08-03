/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    if (!root) {
      return nullptr;
    }

    if (root->right && !root->left) {
      Node *next = root->next;
      while (next && !next->left && !next->right) {
        next = next->next;
      }
      if (!next) {
        // root->right is leaf
        root->right->next = nullptr;
      } else {
        if (next->left) {
          root->right->next = next->left;
        } else if (next->right) {
          root->right->next = next->right;
        }
      }
      connect(root->right);
    }

    if (root->left && !root->right) {
      Node *next = root->next;
      while (next && !next->left && !next->right) {
        next = next->next;
      }
      if (!next) {
        // root->left is leaf
        root->left->next = nullptr;
      } else {
        if (next->left) {
          root->left->next = next->left;
        } else if (next->right) {
          root->left->next = next->right;
        }
      }
      connect(root->left);
    }

    if (root->left && root->right) {
      root->left->next = root->right;
      Node *next = root->next;
      while (next && !next->left && !next->right) {
        next = next->next;
      }
      if (!next) {
        // root->right is leaf
        root->right->next = nullptr;
      } else {
        if (next->left) {
          root->right->next = next->left;
        } else if (next->right) {
          root->right->next = next->right;
        }
      }
      connect(root->right);
      connect(root->left);
    }
    return root;
  }
};
