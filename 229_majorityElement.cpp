class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {

    vector<int> result;

    int x, countX = 0;
    int y, countY = 0;

    for (int num : nums) {

      if (num == x && countX != 0) {
        ++countX;
      } else if (num == y && countY != 0) {
        ++countY;
      } else if (countX == 0) {
        x = num;
        ++countX;
      } else if (countY == 0) {
        y = num;
        ++countY;
      } else {
        --countX;
        --countY;
      }
    }

    countX = 0;
    countY = 0;

    for (int num : nums) {
      if (num == x)
        ++countX;
      else if (num == y)
        ++countY;
    }

    if (countX > nums.size() / 3)
      result.push_back(x);
    if (countY > nums.size() / 3)
      result.push_back(y);

    return result;
  }
};
