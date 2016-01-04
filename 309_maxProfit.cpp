class Solution {
public:
  int maxProfit(vector<int> &prices) {

    const int buy = 0, sell = 1, coolDown = 2;

    int profit[2][3] = {INT_MIN, 0, 0};

    int current = 0, next = 1;
    for (int x = 0, size = prices.size(); x < size; ++x) {
      profit[next][buy] =
          max(profit[current][buy], profit[current][coolDown] - prices[x]);
      profit[next][sell] =
          max(profit[current][sell], profit[current][buy] + prices[x]);
      profit[next][coolDown] =
          max(profit[current][coolDown], profit[current][sell]);

      swap(current, next);
    }

    return max(profit[current][sell], profit[current][coolDown]);
  }
};
