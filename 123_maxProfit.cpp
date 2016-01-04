class Solution {
public:
  int maxProfit(vector<int> &prices) {

    if (prices.size() < 2)
      return 0;

    // balanceState[][0] => buy
    // balanceState[][2] => buy, sell
    // balanceState[][3] => buy, sell, buy
    // balanceState[][4] => buy, sell, buy, sell

    int balanceState[2][4] = {INT_MIN, 0, INT_MIN, 0};
    int current = 0, next = 1;
    for (int i = 0; i < prices.size(); ++i) {
      balanceState[next][0] = max(balanceState[current][0], -prices[i]);
      balanceState[next][1] =
          max(balanceState[current][1], balanceState[current][0] + prices[i]);
      balanceState[next][2] =
          max(balanceState[current][2], balanceState[current][1] - prices[i]);
      balanceState[next][3] =
          max(balanceState[current][3], balanceState[current][2] + prices[i]);

      swap(next, current);
    }

    return balanceState[current][3];
  }
};
