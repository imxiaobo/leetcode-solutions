class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {

    vector<int> product(nums.size(), 1);

    int p = nums[0];
    for (int idx = 1; idx < nums.size(); ++idx) {
      product[idx] = p;
      p *= nums[idx];
    }

    p = nums.back();
    for (int idx = nums.size() - 2; idx >= 0; --idx) {
      product[idx] *= p;
      p *= nums[idx];
    }

    return move(product);
  }
};
