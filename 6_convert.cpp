class Solution {
public:
  string convert(string s, int numRows) {

    if (numRows < 1)
      return "";
    if (numRows == 1)
      return s;

    vector<string> rows(numRows);
    int direction = 1, row = 0;

    for (char c : s) {
      if (row == 0)
        direction = 1;
      else if (row == rows.size() - 1)
        direction = -1;

      rows[row].push_back(c);
      row += direction;
    }

    return std::accumulate(rows.begin(), rows.end(), string());
  }
};
