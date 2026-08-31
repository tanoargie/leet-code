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
  TreeNode *flattenAux(TreeNode *root) {
    if (!root) {
      return nullptr;
    }
    if (!root->left && root->right) {
      flattenAux(root->right);
      return root;
    }
    if (!root->left) {
      return root;
    }
    TreeNode *prevRight = root->right;
    TreeNode *flattenLeft = flattenAux(root->left);
    root->right = flattenLeft;
    root->left = nullptr;
    TreeNode *right = flattenLeft;
    while (right->right) {
      right = right->right;
    }
    right->right = prevRight;
    flattenAux(prevRight);
    return root;
  }
  void flatten(TreeNode *root) {
    if (!root) {
      return;
    }
    root = flattenAux(root);
  }
};
