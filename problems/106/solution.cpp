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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (postorder.empty()) {
      return nullptr;
    }
    int val = postorder.back();
    TreeNode *root = new TreeNode(val);
    postorder.pop_back();
    vector<int>::iterator cut = inorder.begin();
    while (cut != inorder.end() && *cut != val) {
      cut++;
    }
    vector<int> leftInorder(inorder.begin(), cut);
    vector<int> rightInorder(++cut, inorder.end());
    if (rightInorder.empty()) {
      root->right = nullptr;
    } else {
      root->right = buildTree(rightInorder, postorder);
    }
    if (leftInorder.empty()) {
      root->left = nullptr;
    } else {
      root->left = buildTree(leftInorder, postorder);
    }

    return root;
  }
};
