class Solution {
public:
  string longestPalindrome(string s) {

    stringstream ss;
    ss << "$#";
    for (auto c : s)
      ss << c << '#';
    string sss(move(ss.str()));

    int size = sss.size();
    vector<int> len(size, 1);
    int imax = 0, imaxBoundary = 1;

    for (int i = 1; i < size; ++i) {
      if (i < imaxBoundary) {
        len[i] = min(len[2 * imax - i], imaxBoundary - i);
      }

      while (i - len[i] >= 0 && i + len[i] < size &&
             sss[i - len[i]] == sss[i + len[i]]) {
        ++len[i];
      }

      if (len[i] > len[imax]) {
        imax = i;
        imaxBoundary = i + len[i];
      }
    }

    int mid = imax / 2 - 1;
    int length = len[imax] - 1;
    int left = mid - length / 2 + (length % 2 == 0 ? 1 : 0);
    return s.substr(left, length);
  }
};
