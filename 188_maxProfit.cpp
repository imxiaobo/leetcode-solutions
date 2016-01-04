class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {

    findMinMax(prices);
    k = min(k, (int)(prices.size() / 2));

    if (k == 0)
      return 0;

    int size = 2 * k;
    vector<int> balanceCurrent(size);
    vector<int> balanceNext(size);

    for (int idx = 0; idx < size; ++idx) {
      balanceCurrent[idx] = (idx & 1) ? 0 : INT_MIN;
    }

    for (int i = 0; i < prices.size(); ++i) {
      balanceNext[0] = max(balanceCurrent[0], -prices[i]);
      for (int j = 1; j < size; ++j) {
        if (j & 1)
          balanceNext[j] =
              max(balanceCurrent[j], balanceCurrent[j - 1] + prices[i]);
        else
          balanceNext[j] =
              max(balanceCurrent[j], balanceCurrent[j - 1] - prices[i]);
      }
      swap(balanceCurrent, balanceNext);
    }

    return balanceCurrent.back();
  }

  void findMinMax(vector<int> &prices) {
    vector<int> result;

    for (int idx = 0; idx < prices.size(); ++idx) {
      if (idx == 0 || idx == prices.size() - 1) {
        result.push_back(prices[idx]);
      } else {
        if (prices[idx] >= prices[idx - 1] && prices[idx] >= prices[idx + 1] &&
            result.back() != prices[idx]) {
          result.push_back(prices[idx]);
        } else if (prices[idx] <= prices[idx - 1] &&
                   prices[idx] <= prices[idx + 1] &&
                   result.back() != prices[idx]) {
          result.push_back(prices[idx]);
        }
      }
    }

    swap(result, prices);
  }
};
