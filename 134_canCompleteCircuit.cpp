class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int tank = 0, start = 0, total = 0;
    for (int x = 0; x < gas.size(); ++x) {
      tank += gas[x] - cost[x];
      total += tank;

      if (tank < 0) {
        start = x + 1;
        tank = 0;
      }
    }
    return total >= 0 ? start : -1;
  }
};
