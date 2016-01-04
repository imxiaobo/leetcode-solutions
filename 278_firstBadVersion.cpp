// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) { return search(1, n); }

  int search(int left, int right) {
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (isBadVersion(mid))
        right = mid - 1;
      else
        left = mid + 1;
    }
    return left;
  }
};