class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {

    // build adj list
    vector<vector<int>> adj(numCourses);
    for (const auto &edge : prerequisites) {
      adj[edge.second].push_back(edge.first);
    }

    vector<bool> onStack(numCourses, false);
    vector<bool> visited(numCourses, false);

    for (int x = 0; x < numCourses; ++x) {
      if (containsCircle(x, onStack, visited, adj))
        return false;
    }

    return true;
  }

  bool containsCircle(int v, vector<bool> &onStack, vector<bool> &visited,
                      vector<vector<int>> &adj) {
    if (visited[v])
      return false;

    if (onStack[v])
      return true;

    onStack[v] = true;

    for (int v2 : adj[v]) {
      if (containsCircle(v2, onStack, visited, adj))
        return true;
    }

    onStack[v] = false;

    visited[v] = true;

    return false;
  }
};
