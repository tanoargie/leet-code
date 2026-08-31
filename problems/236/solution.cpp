/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return nullptr;
    }
    if (root == p || root == q) {
      return root;
    }
    TreeNode *findRight = lowestCommonAncestor(root->right, p, q);
    TreeNode *findLeft = lowestCommonAncestor(root->left, p, q);
    if (findRight && findLeft) {
      return root;
    } else if (findRight) {
      return findRight;
    } else if (findLeft) {
      return findLeft;
    } else {
      return nullptr;
    }
  }
};
