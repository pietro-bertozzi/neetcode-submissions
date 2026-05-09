class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (dp.back() < nums[i]) dp.push_back(nums[i]);
            else dp[lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin()] = nums[i];
        }
        return dp.size();
    }
};