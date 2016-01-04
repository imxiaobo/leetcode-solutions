class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    if (k == 1 || nums.empty())
      return move(nums);
    vector<int> result;
    deque<int> window;
    for (int idx = 0; idx < nums.size(); ++idx) {
      while (!window.empty() && window.front() + k - 1 < idx) {
        window.pop_front();
      }

      if (window.empty()) {
        window.emplace_front(idx);
      } else if (nums[idx] > nums[window.front()]) {
        window.clear();
        window.emplace_front(idx);
      } else {
        while (nums[idx] > nums[window.back()]) {
          window.pop_back();
        }
        window.emplace_back(idx);
      }

      if (idx >= k - 1)
        result.emplace_back(nums[window.front()]);
    }
    return move(result);
  }
};
