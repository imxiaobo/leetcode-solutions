class Solution {
public:
  int hIndex(vector<int> &citations) {

    sort(citations.begin(), citations.end(), greater<int>());

    int h = 0;
    for (int x = 0; x < citations.size(); ++x) {
      if (citations[x] > x)
        h = max(h, x + 1);
      else
        break;
    }
    return h;
  }
};
