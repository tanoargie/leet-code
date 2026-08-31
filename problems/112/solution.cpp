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
  bool hasPartialPathSum(TreeNode *root, int targetSum, int partialSum = 0) {
    if (!root->left && !root->right) {
      return targetSum == partialSum;
    }

    if (root->left && root->right) {
      return hasPartialPathSum(root->left, targetSum,
                               partialSum + root->left->val) ||
             hasPartialPathSum(root->right, targetSum,
                               partialSum + root->right->val);
    } else if (root->left) {
      return hasPartialPathSum(root->left, targetSum,
                               partialSum + root->left->val);
    } else {
      return hasPartialPathSum(root->right, targetSum,
                               partialSum + root->right->val);
    }
  }
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) {
      return false;
    }
    if (!root->left && !root->right) {
      return root->val == targetSum;
    }
    return hasPartialPathSum(root, targetSum, root->val);
  }
};
