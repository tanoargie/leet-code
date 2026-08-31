class Solution {
public:
  int countArrays(vector<int> &original, vector<vector<int>> &bounds) {
    for (int i = original.size() - 1; i > 0; i--) {
      original[i] = original[i] - original[i - 1];
    }
    for (int k = bounds.size() - 2; k >= 0; k--) {
      bounds[k][0] = max((bounds[k + 1][0] - original[k + 1]), bounds[k][0]);
      bounds[k][1] = min((bounds[k + 1][1] - original[k + 1]), bounds[k][1]);
      if (bounds[k][1] - bounds[k][0] < 0) {
        return 0;
      }
    }

    return bounds[0][1] - bounds[0][0] + 1;
  }
};
