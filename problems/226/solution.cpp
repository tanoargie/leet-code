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
  TreeNode *invertTree(TreeNode *root) {
    if (!root) {
      return root;
    }
    if (root->right && root->left) {
      TreeNode *right = root->right;
      root->right = root->left;
      root->left = right;
      invertTree(root->right);
      invertTree(root->left);
    } else if (root->right) {
      root->left = root->right;
      root->right = nullptr;
      invertTree(root->left);
    } else if (root->left) {
      root->right = root->left;
      root->left = nullptr;
      invertTree(root->right);
    }

    return root;
  }
};
