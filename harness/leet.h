#pragma once

#include <optional>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct GraphNode {
  int val;
  std::vector<GraphNode*> neighbors;
  GraphNode() : val(0), neighbors({}) {}
  GraphNode(int v) : val(v), neighbors({}) {}
  GraphNode(int v, std::vector<GraphNode*> n) : val(v), neighbors(n) {}
};

struct RandomListNode {
  int val;
  RandomListNode* next;
  RandomListNode* random;
  RandomListNode() : val(0), next(nullptr), random(nullptr) {}
  RandomListNode(int v) : val(v), next(nullptr), random(nullptr) {}
};

TreeNode* buildTree(const std::vector<std::optional<int>>& values) {
  if (values.empty() || !values[0]) return nullptr;
  auto* root = new TreeNode(*values[0]);
  std::queue<TreeNode*> q;
  q.push(root);
  size_t i = 1;
  while (i < values.size()) {
    TreeNode* node = q.front();
    q.pop();
    if (values[i]) {
      node->left = new TreeNode(*values[i]);
      q.push(node->left);
    }
    ++i;
    if (i < values.size() && values[i]) {
      node->right = new TreeNode(*values[i]);
      q.push(node->right);
    }
    ++i;
  }
  return root;
}

std::vector<std::optional<int>> toVector(TreeNode* root) {
  std::vector<std::optional<int>> out;
  if (!root) return out;
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* n = q.front();
    q.pop();
    if (n) {
      out.push_back(n->val);
      q.push(n->left);
      q.push(n->right);
    } else {
      out.push_back(std::nullopt);
    }
  }
  while (!out.empty() && !out.back()) out.pop_back();
  return out;
}

ListNode* buildList(const std::vector<int>& values) {
  if (values.empty()) return nullptr;
  auto* head = new ListNode(values[0]);
  ListNode* cur = head;
  for (size_t i = 1; i < values.size(); ++i) {
    cur->next = new ListNode(values[i]);
    cur = cur->next;
  }
  return head;
}

std::vector<int> toVector(ListNode* head) {
  std::vector<int> out;
  for (; head; head = head->next) out.push_back(head->val);
  return out;
}
