class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int slow = 0, fast = 0;
    while (fast != nums.size()) {
      if (nums[fast] == val)
        ++fast;
      else
        nums[slow++] = nums[fast++];
    }
    return slow;
  }
};
