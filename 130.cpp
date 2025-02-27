class Solution {
public:
  void dfs(int i, int j, vector<vector<char>> &board, int rows, int columns) {
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    board[i][j] = 'B';
    for (pair<int, int> direction : directions) {
      int newI = i + direction.first;
      int newJ = j + direction.second;
      bool isValid = newI >= 0 && newJ >= 0 && newI < rows && newJ < columns;
      if (isValid && board[newI][newJ] == 'O') {
        dfs(newI, newJ, board, rows, columns);
      }
    }
  }
  void solve(vector<vector<char>> &board) {
    int rows = board.size();
    int columns = board[0].size();
    for (int j = 0; j < columns; j++) {
      if (board[0][j] == 'O') {
        dfs(0, j, board, rows, columns);
      }
      if (board[rows - 1][j] == 'O') {
        dfs(rows - 1, j, board, rows, columns);
      }
    }
    for (int i = 0; i < rows; i++) {
      if (board[i][0] == 'O') {
        dfs(i, 0, board, rows, columns);
      }
      if (board[i][columns - 1] == 'O') {
        dfs(i, columns - 1, board, rows, columns);
      }
    }
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
        if (board[i][j] == 'B') {
          board[i][j] = 'O';
        }
      }
    }
  }
};
