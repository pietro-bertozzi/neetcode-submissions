class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, 0);
        for (int i = n - 2; i >= 0; --i) {
            int best = 1001;
            for (int j = 1; i + j < n && j <= nums[i]; ++j) {
                if(dp[i + j] >= 0) best = min(dp[i + j], best);
            }
            dp[i] = best == 1001 ? -1 : best + 1;
        }
        return dp[0];
    }
};
