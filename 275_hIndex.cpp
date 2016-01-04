class Solution {
public:
  int hIndex(vector<int> &citations) {

    int size = citations.size(), first = 0, last = size - 1;
    int h = 0;

    while (first <= last) {
      int mid = first + (last - first) / 2;
      if (citations[mid] >= size - mid) {
        h = max(h, size - mid);
        last = mid - 1;
      } else {
        first = mid + 1;
      }
    }

    return h;
  }
};
