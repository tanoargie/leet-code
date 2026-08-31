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
  void zigzagLevelOrderAux(TreeNode *root, int level) {
    if (root) {
      res[level].push_back(root->val);

      zigzagLevelOrderAux(root->left, level + 1);
      zigzagLevelOrderAux(root->right, level + 1);
    }
  }
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    zigzagLevelOrderAux(root, 1);
    vector<vector<int>> result;
    bool fromLeft = true;
    for (auto it = res.begin(); it != res.end(); it++) {
      if (fromLeft) {
        result.push_back(it->second);
      } else {
        reverse(it->second.begin(), it->second.end());
        result.push_back(it->second);
      }
      fromLeft = !fromLeft;
    }

    return result;
  }
};
