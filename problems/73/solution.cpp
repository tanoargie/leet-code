class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    // matrix.size = m
    // matrix[0].size = n
    bool hasZeroFirstRow = false;
    for (int j = 0; !hasZeroFirstRow && j < matrix[0].size(); j++) {
      if (matrix[0][j] == 0) {
        hasZeroFirstRow = true;
      }
    }

    bool hasZeroFirstColumn = false;
    for (int i = 0; !hasZeroFirstColumn && i < matrix.size(); i++) {
      if (matrix[i][0] == 0) {
        hasZeroFirstColumn = true;
      }
    }

    for (int i = 1; i < matrix.size(); i++) {
      // row
      for (int j = 1; j < matrix[0].size(); j++) {
        // column
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    for (int i = 1; i < matrix.size(); i++) {
      for (int j = 1; j < matrix[0].size(); j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    if (hasZeroFirstRow) {
      for (int j = 0; j < matrix[0].size(); j++) {
        matrix[0][j] = 0;
      }
    }

    if (hasZeroFirstColumn) {
      for (int i = 0; i < matrix.size(); i++) {
        matrix[i][0] = 0;
      }
    }
  }
};
