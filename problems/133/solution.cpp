/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
  // past_node -> new_node
  unordered_map<Node *, Node *> newNodes;

public:
  Node *cloneGraph(Node *node) {
    if (!node)
      return nullptr;
    Node *n = new Node(node->val, node->neighbors);
    if (newNodes[node] == nullptr)
      newNodes[node] = n;
    vector<Node *> newNeighbors;
    for (Node *neighbor : node->neighbors) {
      Node *newNeighbor = newNodes[neighbor];
      if (newNodes[neighbor] == nullptr) {
        newNeighbor = cloneGraph(neighbor);
      }
      newNeighbors.push_back(newNeighbor);
    }

    n->neighbors = newNeighbors;
    return n;
  }
};
