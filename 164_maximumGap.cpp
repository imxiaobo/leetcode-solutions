class Solution {
public:
  int maximumGap(vector<int> &nums) {

    if (nums.size() < 2)
      return 0;

    auto minmax = minmax_element(nums.begin(), nums.end());
    int minE = *minmax.first, maxE = *minmax.second;

    if (maxE == minE)
      return 0;

    int bucketRange = (maxE - minE - 1) / (nums.size() - 1) + 1;

    // min max buckets
    vector<pair<int, int>> buckets(nums.size(), make_pair(INT_MAX, INT_MIN));

    for (int idx = 0; idx < nums.size(); ++idx) {
      int bucketIndex = (nums[idx] - minE) / bucketRange;
      auto &bucket = buckets[bucketIndex];
      const auto &number = nums[idx];

      bucket.first = min(number, bucket.first);
      bucket.second = max(number, bucket.second);
    }

    int gap = bucketRange, prevMax = buckets[0].second;
    for (int idx = 1; idx < buckets.size(); ++idx) {
      if (buckets[idx].first != INT_MAX) {
        gap = max(gap, buckets[idx].first - prevMax);
        prevMax = buckets[idx].second;
      }
    }
    return gap;
  }
};
