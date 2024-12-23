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
private:
  map<int, vector<int>> res;

public:
  void levelOrderAux(TreeNode *root, int level) {
    if (root) {
      res[level].push_back(root->val);

      levelOrderAux(root->left, level + 1);
      levelOrderAux(root->right, level + 1);
    }
  }
  vector<vector<int>> levelOrder(TreeNode *root) {
    levelOrderAux(root, 1);
    vector<vector<int>> result;
    for (auto it = res.begin(); it != res.end(); it++) {
      result.push_back(it->second);
    }

    return result;
  }
};
