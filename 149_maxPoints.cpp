/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
  int maxPoints(vector<Point> &points) {

    if (points.size() < 3)
      return points.size();

    int result = 0;

    for (int i = 0; i < points.size() - 1; ++i) {
      unordered_map<double, int> tmp;
      int dup = 0;
      for (int j = i + 1; j < points.size(); ++j) {
        auto &A = points[i];
        auto &B = points[j];

        if (A.x == B.x && A.y == B.y) {
          ++dup;
          continue;
        }

        double k = (B.x == A.x) ? numeric_limits<double>::max()
                                : (double)(B.y - A.y) / (B.x - A.x);

        ++tmp[k];
      }

      int m = 0;
      for (auto &p : tmp) {
        m = max(p.second, m);
      }
      result = max(result, m + dup + 1);
    }

    return result;
  }
};
