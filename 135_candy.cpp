class Solution {
public:
  int candy(vector<int> &ratings) {
    int size = ratings.size();
    if (size < 2)
      return size;

    vector<int> candies(size, 1);
    for (int idx = 1; idx < size; ++idx) {
      if (ratings[idx] > ratings[idx - 1]) {
        candies[idx] = candies[idx - 1] + 1;
      }
    }
    for (int idx = size - 2; idx >= 0; --idx) {
      if (ratings[idx] > ratings[idx + 1] && candies[idx] <= candies[idx + 1]) {
        candies[idx] = candies[idx + 1] + 1;
      }
    }

    return accumulate(candies.begin(), candies.end(), 0);
  }
};
