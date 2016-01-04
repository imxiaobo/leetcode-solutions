class Solution {
public:
  vector<int> getRow(int rowIndex) {

    if (rowIndex < 0)
      return {};
    if (rowIndex == 0)
      return {1};

    vector<int> t = {1};

    while (rowIndex > 0) {
      t.push_back(0);
      for (int x = t.size() - 1; x > 0; --x) {
        t[x] += t[x - 1];
      }
      --rowIndex;
    }

    return move(t);
  }
};
