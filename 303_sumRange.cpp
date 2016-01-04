class NumArray {
  vector<int> accumulate;

public:
  NumArray(vector<int> &nums) {
    accumulate.push_back(0);
    for (int num : nums)
      accumulate.push_back(accumulate.back() + num);
  }

  int sumRange(int i, int j) { return accumulate[j + 1] - accumulate[i]; }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
