class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit = 0;
    if (prices.size() < 2)
      return profit;

    for (int idx = 1; idx < prices.size(); ++idx) {
      int delta = prices[idx] - prices[idx - 1];
      if (delta > 0) {
        profit += delta;
      }
    }
    return profit;
  }
};
