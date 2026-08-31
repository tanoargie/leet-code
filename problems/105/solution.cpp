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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (inorder.size() == 0) {
      return nullptr;
    }
    int start = preorder[0];
    preorder.erase(preorder.begin());
    TreeNode *root = new TreeNode(start);
    int posInorder = 0;
    if (inorder.size() == 1 && inorder[posInorder] == start) {
      return root;
    }
    while (posInorder < inorder.size() && inorder[posInorder] != start) {
      posInorder++;
    }
    vector<int> leftInorder(inorder.begin(), inorder.begin() + posInorder);
    vector<int> rightInorder(inorder.begin() + posInorder + 1, inorder.end());
    TreeNode *leftTree = buildTree(preorder, leftInorder);
    TreeNode *rightTree = buildTree(preorder, rightInorder);
    root->left = leftTree;
    root->right = rightTree;
    return root;
  }
};
