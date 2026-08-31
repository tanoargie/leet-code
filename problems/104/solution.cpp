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
  int getMaxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    if (!root->right && !root->left) {
      return 1;
    }
    return max(1 + getMaxDepth(root->right), 1 + getMaxDepth(root->left));
  }
  int maxDepth(TreeNode *root) { return getMaxDepth(root); }
};
