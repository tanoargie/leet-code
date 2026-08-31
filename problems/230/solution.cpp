/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  void inOrderAux(TreeNode *root, vector<int> &res) {
    if (!root)
      return;
    if (root->left)
      inOrderAux(root->left, res);
    res.push_back(root->val);
    if (root->right)
      inOrderAux(root->right, res);
  }
  int kthSmallest(TreeNode *root, int k) {
    vector<int> inOrder;
    inOrderAux(root, inOrder);
    return inOrder[k - 1];
  }
};
