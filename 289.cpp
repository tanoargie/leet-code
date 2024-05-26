class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        int countLive = 0;
        for (int row = i - 1; row < i + 2; row++) {
          for (int column = j - 1; column < j + 2; column++) {
            if (row >= 0 && row < board.size() && column >= 0 &&
                column < board[0].size() &&
                (board[row][column] == 1 || board[row][column] == 4 ||
                 board[row][column] == 5)) {
              countLive++;
            }
          }
        }

        if (board[i][j] == 0 && countLive == 3) {
          board[i][j] = 3;
        }

        if (board[i][j] == 1) {
          countLive--;
          if (countLive > 3) {
            board[i][j] = 5;
          } else if (countLive < 2) {
            board[i][j] = 4;
          }
        }
      }
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == 5 || board[i][j] == 4) {
          board[i][j] = 0;
        }
        if (board[i][j] == 3) {
          board[i][j] = 1;
        }
      }
    }
  }
};
