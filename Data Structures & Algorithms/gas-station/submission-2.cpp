class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) <
            accumulate(cost.begin(), cost.end(), 0)
        ) return -1;
        int n = gas.size();
        int sum = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                sum = 0;
                result = i + 1;
            }
        }
        return result;
    }
};