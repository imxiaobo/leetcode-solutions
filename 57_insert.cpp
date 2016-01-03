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
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;

    bool inserted = false;
    for (int idx = 0; idx < intervals.size(); ++idx) {
      if (!inserted) {
        if (intervals[idx].start < newInterval.start) {
          result.emplace_back(intervals[idx]);
        } else {
          appendOrMerge(result, newInterval);
          appendOrMerge(result, intervals[idx]);
          inserted = true;
        }
      } else {
        appendOrMerge(result, intervals[idx]);
      }
    }

    if (!inserted) {
      appendOrMerge(result, newInterval);
    }

    return result;
  }

  void appendOrMerge(vector<Interval> &intervals, const Interval &newInterval) {
    if (intervals.empty()) {
      intervals.emplace_back(newInterval);
    } else {
      if (newInterval.start >= intervals.back().end + 1) {
        intervals.emplace_back(newInterval);
      } else {
        intervals.back().end = max(newInterval.end, intervals.back().end);
      }
    }
  }
};
