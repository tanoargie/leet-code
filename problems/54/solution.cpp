class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    enum Direction { Right, Down, Left, Up };
    Direction current = Right;
    vector<int> result;
    int count = 0;
    int currentUp = 0;
    int currentRight = matrix[0].size() - 1;
    int currentDown = matrix.size() - 1;
    int currentLeft = 0;
    int total = matrix[0].size() * matrix.size();
    while (count < total) {
      if (current == Right) {
        int i = currentLeft;
        while (count < total && i <= currentRight) {
          count++;
          result.push_back(matrix[currentUp][i]);
          i++;
        }
        current = Down;
        currentUp++;
      }
      if (current == Down) {
        int i = currentUp;
        while (count < total && i <= currentDown) {
          count++;
          result.push_back(matrix[i][currentRight]);
          i++;
        }
        current = Left;
        currentRight--;
      }
      if (current == Left) {
        int i = currentRight;
        while (count < total && i >= currentLeft) {
          count++;
          result.push_back(matrix[currentDown][i]);
          i--;
        }
        current = Up;
        currentDown--;
      }
      if (current == Up) {
        int i = currentDown;
        while (count < total && i >= currentUp) {
          count++;
          result.push_back(matrix[i][currentLeft]);
          i--;
        }
        current = Right;
        currentLeft++;
      }
    }

    return result;
  }
};
