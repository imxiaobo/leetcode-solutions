class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

    int insertIndex = m + n - 1;

    while (true) {
      if (m == 0) {
        while (n != 0) {
          nums1[insertIndex] = nums2[n - 1];
          --insertIndex;
          --n;
        }
        return;
      } else if (n == 0) {
        return;
      }
      if (nums1[m - 1] > nums2[n - 1]) {
        nums1[insertIndex] = nums1[m - 1];
        --insertIndex;
        --m;
      } else {
        nums1[insertIndex] = nums2[n - 1];
        --insertIndex;
        --n;
      }
    }
  }
};
