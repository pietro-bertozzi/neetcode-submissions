class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int one = 0, two = 0;
        for (int i = 2; i <= n; ++i) {
            if (i % 2) two = min(two + cost[i - 2], one + cost[i - 1]);
            else one = min(one + cost[i - 2], two + cost[i - 1]);
        }
        return n % 2 ? two : one;
    }
};
