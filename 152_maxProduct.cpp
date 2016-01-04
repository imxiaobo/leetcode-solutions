class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int minProduct = nums[0], maxProduct = nums[0], result = nums[0];
    for (int idx = 1; idx < nums.size(); ++idx) {
      int newMinProduct = nums[idx] * minProduct,
          newMaxProduct = nums[idx] * maxProduct;
      minProduct = min(nums[idx], min(newMinProduct, newMaxProduct));
      maxProduct = max(nums[idx], max(newMinProduct, newMaxProduct));
      result = max(result, maxProduct);
    }
    return result;
  }
};
