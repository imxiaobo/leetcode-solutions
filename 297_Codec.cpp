/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {

    string output = "[";
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      auto *t = q.front();
      q.pop();
      if (!t) {
        output += "null,";
      } else {
        output += (to_string(t->val) + ",");
        q.push(t->left);
        q.push(t->right);
      }
    }

    output.back() = ']';
    return output;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {

    vector<TreeNode *> nodes;
    int b = 1, e = 1;
    while (e < data.size()) {
      while (e < data.size() && data[e] != ',' && data[e] != ']')
        ++e;
      auto s = data.substr(b, e - b);
      if (s == "null")
        nodes.push_back(nullptr);
      else
        nodes.push_back(new TreeNode(atoi(s.c_str())));
      b = e + 1;
      e = b;
    }

    for (int parent = 0, left = 1, right = 2; parent < nodes.size(); ++parent) {
      if (nodes[parent]) {
        nodes[parent]->left = nodes[left];
        nodes[parent]->right = nodes[right];
        left += 2;
        right += 2;
      }
    }

    return nodes[0];
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
