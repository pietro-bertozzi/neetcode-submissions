class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = n - 1, end = 0, tank = gas[start] - cost[start];
        while (start != end) {
            if (tank > 0) {
                tank -= cost[end];
                tank += gas[end++];
            } else {
                tank -= cost[--start];
                tank += gas[start];
            }
        }
        return tank < 0 ? -1 : start;
    }
};
