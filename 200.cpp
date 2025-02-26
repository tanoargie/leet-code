class Solution {
public:
  bool isSafeToTravel(int i, int j, int rows, int cols,
                      vector<vector<char>> &grid,
                      vector<vector<bool>> &visited) {
    return i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] == '1' &&
           !visited[i][j];
  }
  void dfsIsland(int i, int j, int &number, int rows, int cols,
                 vector<vector<char>> &grid, vector<vector<bool>> &visited) {
    visited[i][j] = true;
    vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (pair<int, int> k : directions) {
      if (isSafeToTravel(i + k.first, j + k.second, rows, cols, grid,
                         visited)) {
        dfsIsland(i + k.first, j + k.second, number, rows, cols, grid, visited);
      }
    }
  }
  int numIslands(vector<vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int number = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (visited[i][j] == false && grid[i][j] == '1') {
          dfsIsland(i, j, number, rows, cols, grid, visited);
          number++;
        }
      }
    }
    return number;
  }
};
