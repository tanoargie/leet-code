class Solution {
private:
  map<int, int> res;

public:
  int climbStairs(int n) {
    res[1] = 1;
    res[2] = 2;
    if (res[n] == 0) {
      res[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
    return res[n];
  }
};
