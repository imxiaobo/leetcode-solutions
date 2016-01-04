class Solution {
public:
  int numSquares(int n) {

    vector<int> visited(n, 0);
    queue<pair<int, int>> q;
    q.emplace(n, 0);

    bool found = false;
    int result = INT_MAX;

    while (!q.empty()) {
      auto elem = q.front();
      int remain = elem.first;
      int count = elem.second;
      q.pop();

      if (remain == 0) {
        found = true;
        result = min(result, count);
      }

      else if (!found) {
        for (int i = sqrt(remain); i >= 1; --i) {
          int next = remain - i * i;
          if (visited[next] == 0) {
            q.emplace(next, count + 1);
            visited[next] = 1;
          }
        }
      }
    }

    return result;
  }
};
