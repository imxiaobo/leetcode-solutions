/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() <= 1)
      return move(intervals);
    vector<Interval> result;
    sort(intervals.begin(), intervals.end(),
         [](const Interval &lhs, const Interval &rhs) {
           return lhs.start < rhs.start;
         });

    for (const auto &i : intervals) {
      if (result.empty() || i.start > result.back().end) {
        result.emplace_back(i);
      } else {
        result.back().end = max(result.back().end, i.end);
      }
    }
    return move(result);
  }
};
