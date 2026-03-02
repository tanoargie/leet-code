class Solution {
public:
  int recursion(int n, vector<int> &dp) {
    if (n == 1)
      dp[n] = 1;
    if (n == 2)
      dp[n] = 2;
    if (dp[n] == 0) {
      dp[n] = recursion(n - 1, dp) + recursion(n - 2, dp);
    }
    return dp[n];
  }
  int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    return recursion(n, dp);
  }
};
