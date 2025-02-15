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
  bool isWithinLimits(TreeNode *root, long long min, long long max) {
    if (!root)
      return true;
    bool currentValid = root->val < max && root->val > min;
    return currentValid && isWithinLimits(root->left, min, root->val) &&
           isWithinLimits(root->right, root->val, max);
  }
  bool isValidBST(TreeNode *root) {
    return isWithinLimits(root->left, LLONG_MIN, root->val) &&
           isWithinLimits(root->right, root->val, LLONG_MAX);
  }
};
