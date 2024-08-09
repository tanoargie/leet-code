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
  void dfs(TreeNode *node, vector<int> &path, vector<vector<int>> &paths) {
    if (!node)
      return;
    path.push_back(node->val);

    if (!node->left && !node->right) {
      paths.push_back(path);
    } else {
      dfs(node->left, path, paths);
      dfs(node->right, path, paths);
    }
    path.pop_back();
  }

  int sumNumbers(TreeNode *root) {
    vector<vector<int>> numbers;
    vector<int> path;
    dfs(root, path, numbers);

    int sum = 0;
    for (int i = 0; i < numbers.size(); i++) {
      long long number = 0;
      long long multiplier = 1;
      for (int j = numbers[i].size() - 1; j >= 0; j--) {
        number += numbers[i][j] * multiplier;
        multiplier *= 10;
      }
      sum += number;
    }
    return sum;
  }
};
