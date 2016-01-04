class Solution {
public:
  int maxProfit(vector<int> &prices) {

    if (prices.empty())
      return 0;

    int buy = prices[0];
    int profit = -prices[0];

    for (auto price : prices) {
      buy = min(buy, price);
      profit = max(profit, price - buy);
    }

    return profit;
  }
};
