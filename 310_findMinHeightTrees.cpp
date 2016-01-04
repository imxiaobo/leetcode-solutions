class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {

    if (n == 0)
      return {};
    if (n == 1)
      return {0};
    if (n == 2)
      return {0, 1};

    vector<int> leafs, nextLeafs;
    auto graph = buildGraph(n, edges);

    for (int v = 0; v < n; ++v) {
      // leaf
      if (graph[v].size() == 1) {
        leafs.push_back(v);
      }
    }

    while (true) {
      for (auto &leaf : leafs) {
        for (auto &neighbor : graph[leaf]) {
          graph[neighbor].erase(leaf);
          if (graph[neighbor].size() == 1) {
            nextLeafs.push_back(neighbor);
          }
        }
      }

      if (nextLeafs.empty())
        return leafs;

      swap(nextLeafs, leafs);
      nextLeafs.clear();
    }
  }

  vector<unordered_set<int>> buildGraph(int n, vector<pair<int, int>> &edges) {
    vector<unordered_set<int>> graph(n);
    for (const auto &e : edges) {
      graph[e.first].insert(e.second);
      graph[e.second].insert(e.first);
    }
    return graph;
  }
};
