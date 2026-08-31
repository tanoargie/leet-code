class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int max_profit = 0;
    int buy = prices[0];
    for (int i = 0; i < prices.size(); i++) {
      int profit = prices[i] - buy;
      if (profit > 0) {
        max_profit += profit;
      }
      buy = prices[i];
    }
    return max_profit;
  }
};
