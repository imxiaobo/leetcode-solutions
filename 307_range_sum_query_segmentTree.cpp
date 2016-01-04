class NumArray {
  struct SegmentTreeNode {
    int from, to, val;
    unique_ptr<SegmentTreeNode> left, right;
    SegmentTreeNode(int from, int to)
        : from(from), to(to), val(0), left(nullptr), right(nullptr) {}
  };

  unique_ptr<SegmentTreeNode> build(vector<int> &nums, int from, int to) {
    if (from > to) {
      return nullptr;
    }

    unique_ptr<SegmentTreeNode> node(new SegmentTreeNode(from, to));
    if (from == to) {
      node->val = nums[from];
    } else {
      int mid = from + (to - from) / 2;
      auto left = build(nums, from, mid);
      auto right = build(nums, mid + 1, to);
      node->val = left->val + right->val;
      node->left = move(left);
      node->right = move(right);
    }

    return move(node);
  }

  void update(unique_ptr<SegmentTreeNode> &node, int i, int val) {
    if (node->from == node->to) {
      node->val = val;
    } else {
      int mid = node->from + (node->to - node->from) / 2;
      if (i <= mid) {
        update(node->left, i, val);
      } else {
        update(node->right, i, val);
      }
      node->val = node->left->val + node->right->val;
    }
  }

  int query(unique_ptr<SegmentTreeNode> &node, int i, int j) {
    if (i == node->from && j == node->to) {
      return node->val;
    } else {
      int mid = node->from + (node->to - node->from) / 2;
      if (i > mid) {
        return query(node->right, i, j);
      } else if (j <= mid) {
        return query(node->left, i, j);
      }

      return query(node->left, i, mid) + query(node->right, mid + 1, j);
    }
  }

  unique_ptr<SegmentTreeNode> root;

public:
  NumArray(vector<int> &nums) : root(build(nums, 0, nums.size() - 1)) {}

  void update(int i, int val) { update(root, i, val); }

  int sumRange(int i, int j) { return query(root, i, j); }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
