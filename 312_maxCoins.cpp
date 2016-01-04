class Solution {
public:
  int maxCoins(vector<int> &nums) {

    vector<int> balloons;
    nums.push_back(1);
    for (auto n : nums) {
      if (n > 0) {
        balloons.push_back(n);
      }
    }
    balloons.push_back(1);

    vector<vector<int>> memo(balloons.size(), vector<int>(balloons.size(), 0));

    return maxCoins(balloons, 0, balloons.size() - 1, memo);
  }

  int maxCoins(vector<int> &balloons, int first, int last,
               vector<vector<int>> &memo) {
    auto &coins = memo[first][last];
    if (coins != 0)
      return coins;
    // last round burst
    for (int burst = first + 1; burst < last; ++burst) {
      coins = max(coins, balloons[first] * balloons[burst] * balloons[last] +
                             maxCoins(balloons, first, burst, memo) +
                             maxCoins(balloons, burst, last, memo));
    }

    return coins;
  }
};
