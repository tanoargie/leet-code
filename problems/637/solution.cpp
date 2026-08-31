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
        unordered_map<long long, long long> sums;
        unordered_map<long long, long long> nodes;
    public:
        void averageOfLevel(TreeNode* root, int level) {
            sums[level] += root->val;
            nodes[level] += 1;
            if (root->left) averageOfLevel(root->left, level + 1);
            if (root->right) averageOfLevel(root->right, level + 1);
        }
        vector<double> averageOfLevels(TreeNode* root) {
            vector<double> averages;
            int level = 1;
            averageOfLevel(root, level);
            unordered_map<long long, long long>::iterator it = sums.find(level);
            while (it != sums.end()) {
                averages.push_back((double)it->second / (double)nodes.at(it->first));
                it = sums.find(++level);
            }

            return averages;
        }
};