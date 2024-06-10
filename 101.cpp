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
  bool isMirror(TreeNode *root1, TreeNode *root2) {
    if (root1 && root2) {
      cout << root1->val << " " << root2->val << endl;
    }
    if (!root1 && !root2) {
      return true;
    } else if ((root1->left && !root2->right) ||
               (!root1->left && root2->right)) {
      return false;
    } else if ((root1->right && !root2->left) ||
               (!root1->right && root2->left)) {
      return false;
    } else if (!root1->right && !root1->left && !root2->right && !root2->left) {
      return root1->val == root2->val;
    }
    return root1->val == root2->val && isMirror(root1->left, root2->right) &&
           isMirror(root2->left, root1->right);
  }
  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    } else if (root->left && !root->right) {
      return false;
    } else if (!root->left && root->right) {
      return false;
    } else if (!root->left && !root->right) {
      return true;
    }
    return root->left->val == root->right->val &&
           isMirror(root->right, root->left);
  }
};
