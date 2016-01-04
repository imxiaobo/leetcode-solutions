class Solution {

  struct Node {
    unsigned long long num;
    int prime;
    int uglyIdx;
    Node() = default;
    Node(const Node &) = default;
    Node &operator=(const Node &) = default;
    Node &operator=(Node &&) = default;
    Node(Node &&) = default;
    Node(unsigned long long num, int prime, int uglyIdx)
        : num(num), prime(prime), uglyIdx(uglyIdx) {}
    // for min heap
    bool operator<(const Node &rhs) const { return num > rhs.num; }
  };

public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {

    priority_queue<Node> pq;
    vector<unsigned long long> result;
    result.reserve(n);
    result.push_back(1);

    for (int idx = 0; idx < primes.size(); ++idx) {
      pq.emplace(primes[idx], primes[idx], 0);
    }

    for (int idx = 1; idx < n; ++idx) {
      result.push_back(pq.top().num);
      // skip duplicates
      while (pq.top().num == result.back()) {
        auto tmp = pq.top();
        pq.pop();
        pq.emplace(result[tmp.uglyIdx + 1] * tmp.prime, tmp.prime,
                   tmp.uglyIdx + 1);
      }
    }

    return result.back();
  }
};
