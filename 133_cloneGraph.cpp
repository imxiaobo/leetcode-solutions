/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

    if (!node)
      return nullptr;

    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mapping;

    copyGraph(mapping, node);
    connectNeighbors(mapping);

    return mapping[node];
  }

  void copyGraph(
      unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &mapping,
      UndirectedGraphNode *vertex) {
    if (mapping.find(vertex) == mapping.end()) {
      mapping.emplace(vertex, new UndirectedGraphNode(vertex->label));
      for (auto *neighbor : vertex->neighbors) {
        copyGraph(mapping, neighbor);
      }
    }
  }

  void connectNeighbors(
      unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &mapping) {
    for (auto &kv : mapping) {
      for (auto *neighbor : kv.first->neighbors) {
        kv.second->neighbors.push_back(mapping[neighbor]);
      }
    }
  }
};
