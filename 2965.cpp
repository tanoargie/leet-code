class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    vector<int> res(2, 0);
    vector<int> appearances(2501, 0);
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        appearances[grid[i][j]]++;
      }
    }
    for (int i = 0; i <= grid.size() * grid.size() && i < appearances.size();
         i++) {
      if (appearances[i] == 2) {
        res[0] = i;
      } else if (appearances[i] == 0) {
        res[1] = i;
      }
    }

    return res;
  }
};
