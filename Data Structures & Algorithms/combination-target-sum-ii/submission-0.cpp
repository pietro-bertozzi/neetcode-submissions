class Solution {
public:
    void dfs(int start, vector<int>& nums, int target, vector<int>& cur, vector<vector<int>>& result) {
        if (!target) {
            result.push_back(cur);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (target < nums[i]) break;
            if (i > start && nums[i] == nums[i - 1]) continue;
            cur.push_back(nums[i]);
            dfs(i + 1, nums, target - nums[i], cur, result);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        vector<vector<int>> result;
        dfs(0, nums, target, cur, result);
        return result;
    }
};