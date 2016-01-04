class Solution {
public:
  string minWindow(string s, string t) {

    int freq[128] = {0};
    for (char c : t) {
      ++freq[c];
    }
    int required = t.size(), size = s.size();
    // window = [wb, we)
    int wb = 0, we = 0, windowBegin, windowEnd, minWindowSize = INT_MAX;
    while (wb < size && we <= size) {
      // window does not contain all required chars in t
      if (required > 0) {
        if (we == size)
          break;
        if (--freq[s[we++]] >= 0)
          --required;
      } else {
        int windowSize = we - wb;
        if (windowSize < minWindowSize) {
          minWindowSize = windowSize;
          windowBegin = wb;
          windowEnd = we;
        }
        if (++freq[s[wb++]] > 0)
          ++required;
      }
    }
    if (minWindowSize == INT_MAX)
      return "";
    return s.substr(windowBegin, minWindowSize);
  }
};
