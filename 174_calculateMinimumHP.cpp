class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {

    if (dungeon.empty())
      return 1;

    vector<vector<int>> memo(dungeon.size(), vector<int>(dungeon[0].size(), 0));

    return calculateMinimumHP(dungeon, 0, 0, memo);
  }

  int calculateMinimumHP(vector<vector<int>> &dungeon, int row, int column,
                         vector<vector<int>> &memo) {
    if (memo[row][column] != 0)
      return memo[row][column];

    if ((row == dungeon.size() - 1) && (column == dungeon[row].size() - 1)) {
      memo[row][column] = max(1 - dungeon[row][column], 1);
    } else {
      int minDown = INT_MAX, minRight = INT_MAX;

      if (row + 1 < dungeon.size()) {
        minRight = calculateMinimumHP(dungeon, row + 1, column, memo);
      }
      if (column + 1 < dungeon[row].size()) {
        minDown = calculateMinimumHP(dungeon, row, column + 1, memo);
      }

      memo[row][column] = max(max(1 - dungeon[row][column], 1),
                              min(minDown, minRight) - dungeon[row][column]);
    }

    return memo[row][column];
  }
};
