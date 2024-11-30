/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        int res = -1000;
    public:
        int maxPathSumAux(TreeNode* root) {
            if (!root) return 0;
            int lsum = max(maxPathSumAux(root->left), 0);
            int rsum = max(maxPathSumAux(root->right), 0);
            int maxChild = max(lsum, rsum);
            res = max(res, root->val + lsum + rsum);
            return root->val + maxChild;
        }
        int maxPathSum(TreeNode* root) {
            maxPathSumAux(root);
            return res;
        }
};