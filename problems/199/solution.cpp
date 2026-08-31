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
        vector<int> res;
        map<int, int> rights;
    public:
        void rightSideViewAux(TreeNode* root, int level) {
            if (root) {
                rights[level] = root->val;
                if (root->left) {
                    rightSideViewAux(root->left, level + 1);
                }
                if (root->right) {
                    rightSideViewAux(root->right, level + 1);
                }
            }
        }
        vector<int> rightSideView(TreeNode* root) {
            rightSideViewAux(root, 1);
            vector<int> res;
            for (auto it = rights.begin(); it != rights.end(); it++) {
                res.push_back(it->second);
            }

            return res;
        }
};
