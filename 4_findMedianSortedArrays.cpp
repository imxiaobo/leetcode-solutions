class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

    int m = nums1.size();
    int n = nums2.size();

    if ((m + n) % 2 == 0) {
      return (findKth(nums1.begin(), m, nums2.begin(), n, (m + n) / 2) +
              findKth(nums1.begin(), m, nums2.begin(), n, (m + n) / 2 + 1)) /
             2.0;
    } else {
      return findKth(nums1.begin(), m, nums2.begin(), n, (m + n) / 2 + 1);
    }
  }

  int findKth(vector<int>::iterator A, int m, vector<int>::iterator B, int n,
              int k) {
    if (m > n) {
      swap(A, B);
      swap(m, n);
    }

    if (m == 0) {
      return B[k - 1];
    }

    if (k == 1) {
      return min(*A, *B);
    }

    int i = min(k / 2, m);
    int j = k - i;

    if (A[i - 1] < B[j - 1]) {
      return findKth(A + i, m - i, B, n, k - i);
    }

    else if (A[i - 1] > B[j - 1]) {
      return findKth(A, m, B + j, n - j, k - j);
    }

    else
      return A[i - 1];
  }
};
