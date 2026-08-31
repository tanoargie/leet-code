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
    public:
        void inOrderAux(TreeNode* root, vector<int>& res) {
            if (!root) return;
            if (root->left) inOrderAux(root->left, res);
            res.push_back(root->val);
            if (root->right) inOrderAux(root->right, res);
        }
        int getMinimumDifference(TreeNode* root) {
            vector<int> inOrder;
            inOrderAux(root, inOrder);
            int min = inOrder[1] - inOrder[0];
            for (int i = 2; i < inOrder.size(); i++) {
                int diff = inOrder[i] - inOrder[i-1];
                if (diff < min) {
                    min = diff;
                }
            }
            return min;
        }
};
