class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    vector<int> numIndices;
    vector<int> count(nums.size(), 0);
    for (int idx = 0; idx < nums.size(); ++idx) {
      numIndices.push_back(idx);
    }
    sort(nums, numIndices, count);
    return count;
  }

  void sort(const vector<int> &nums, vector<int> &numIndices,
            vector<int> &count) {
    if (numIndices.size() <= 1)
      return;

    vector<int> leftIndices(numIndices.begin(),
                            numIndices.begin() + numIndices.size() / 2);
    vector<int> rightIndices(numIndices.begin() + numIndices.size() / 2,
                             numIndices.end());
    sort(nums, leftIndices, count);
    sort(nums, rightIndices, count);
    numIndices = move(merge(nums, leftIndices, rightIndices, count));
  }

  vector<int> merge(const vector<int> &nums, const vector<int> &leftIndices,
                    const vector<int> &rightIndices, vector<int> &count) {
    vector<int> merged;

    auto l = leftIndices.begin();
    auto r = rightIndices.begin();

    int skipCount = 0;

    while (l != leftIndices.end() && r != rightIndices.end()) {
      if (nums[*l] > nums[*r]) {
        ++skipCount;
        merged.push_back(*r++);
      } else {
        count[*l] += skipCount;
        merged.push_back(*l++);
      }
    }

    while (l != leftIndices.end()) {
      count[*l] += skipCount;
      merged.push_back(*l++);
    }

    while (r != rightIndices.end()) {
      merged.push_back(*r++);
    }

    return merged;
  }
};
