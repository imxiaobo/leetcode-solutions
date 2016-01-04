class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    // calculate areas of two square
    int area1 = (C - A) * (D - B);
    int area2 = (G - E) * (H - F);
    // calculate area of overlap
    int x = max(A, E) > min(C, G) ? 0 : min(C, G) - max(A, E);
    int y = max(B, F) > min(D, H) ? 0 : min(D, H) - max(B, F);
    int area3 = x * y;
    // haha!
    return area1 + area2 - area3;
  }
};
