class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % 2) return false;
        int target = sum / 2;
        bitset<10001> dp;
        dp[0] = 1;
        for (int n : nums) dp |= dp << n;
        return dp[target];
    }
};