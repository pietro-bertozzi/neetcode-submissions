class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n, false);
        for(int i = 0; i < n; ++i) {
            if (seen[nums[i] - 1]) return nums[i];
            seen[nums[i] - 1] = true;
        }
    }
};
