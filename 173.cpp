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
class BSTIterator {
    private:
        stack<TreeNode*> s;

    public:
        void inOrder(TreeNode* root) {
            if (root->right != nullptr) {
                inOrder(root->right);
            }
            s.push(root);
            if (root->left != nullptr) {
                inOrder(root->left);
            }
        }

        BSTIterator(TreeNode* root) {
            inOrder(root);
        }
        
        int next() {
            TreeNode* top = s.top();
            s.pop();
            return top->val;
        }
        
        bool hasNext() {
            return !s.empty();
        }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */