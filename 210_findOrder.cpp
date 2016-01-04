class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {

    vector<vector<int>> graph(numCourses);
    for (const auto &edge : prerequisites) {
      graph[edge.second].push_back(edge.first);
    }
    return topologicalSort(graph);
  }

  vector<int> topologicalSort(const vector<vector<int>> &graph) {
    vector<int> result;
    stack<int> sorted;
    vector<int> visited(graph.size(), 0), inPath(graph.size(), 0);

    for (int vertex = 0; vertex < graph.size(); ++vertex) {
      if (!topologicalSortUtil(graph, vertex, sorted, visited, inPath)) {
        return {};
      }
    }

    while (!sorted.empty()) {
      result.push_back(sorted.top());
      sorted.pop();
    }

    return result;
  }

  bool topologicalSortUtil(const vector<vector<int>> &graph, int n,
                           stack<int> &sorted, vector<int> &visited,
                           vector<int> &inPath) {
    if (visited[n])
      return true;
    // detect circle
    if (inPath[n])
      return false;

    inPath[n] = 1;
    for (auto neighbor : graph[n]) {
      if (!topologicalSortUtil(graph, neighbor, sorted, visited, inPath))
        return false;
    }
    sorted.push(n);
    inPath[n] = 0;

    visited[n] = 1;
    return true;
  }
};
