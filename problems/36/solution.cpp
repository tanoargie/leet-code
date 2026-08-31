class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    bool isValid = true;
    int check10Squares[9][10];
    int check10Column[9][10] = {0};
    int check10Row[9][10] = {0};
    for (int i = 0; i < board.size(); i++) {
      // row i
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] != '.') {
          if (check10Row[i][board[i][j] - '0'] > 0) {
            isValid = false;
            return isValid;
          }
          check10Row[i][board[i][j] - '0']++;
          // compute for squares
          int squareLocation = (j / 3) * 3 + (i / 3);

          if (check10Squares[squareLocation][board[i][j] - '0'] > 0) {
            isValid = false;
            return isValid;
          }
          check10Squares[squareLocation][board[i][j] - '0']++;
          // compute for columns
          if (check10Column[j][board[i][j] - '0'] > 0) {
            isValid = false;
            return isValid;
          }
          check10Column[j][board[i][j] - '0']++;
        }
      }
    }

    return isValid;
  }
};
