class Solution {
public:
  int singleNumber(vector<int> &nums) {

    int a = 0, b = 0;
    // counter state transition:
    // ab: 00->01->10->00 (3 times)
    //
    // ab(current)    c(in)   ab(next)
    //=================================
    // 00             0/1     00/01
    // 01             0/1     01/10
    // 10             0/1     10/00
    //
    // a = (a&~b&~c)|(~a&b&c)
    // b = (~a&b&~c)|(~a&~b&c)

    for (int c : nums) {
      int nextA = (a & ~b & ~c) | (~a & b & c);
      int nextB = (~a & b & ~c) | (~a & ~b & c);
      a = nextA;
      b = nextB;
    }
    return a | b;
  }
};
