class Solution {
public:
  long long coloredCells(int n) {
    long long res = 2 * n - 1;
    n--;
    while (n > 0) {
      res += (2 * n - 1) * 2;
      n--;
    }
    return res;
  }
};
