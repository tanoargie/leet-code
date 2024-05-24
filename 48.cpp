class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    // transpose matrix
    for (int i = 0; i < n; i++) {
      // row
      for (int j = i + 1; j < n; j++) {
        // column
        // swap(matrix[i][j], matrix[j][i]);
        int pivot = matrix[j][i];
        matrix[j][i] = matrix[i][j];
        matrix[i][j] = pivot;
      }
    }

    // reverse matrix in terms of columns
    for (int i = 0; i < n; i++) {
      // row
      for (int j = 0; j < n / 2; j++) {
        // column
        // swap(matrix[i][j], matrix[i][n-1-j]);
        int pivot = matrix[i][n - 1 - j];
        matrix[i][n - 1 - j] = matrix[i][j];
        matrix[i][j] = pivot;
      }
    }
  }
};
