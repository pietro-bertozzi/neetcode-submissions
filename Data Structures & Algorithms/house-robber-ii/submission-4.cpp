class Solution {
public:
    int rob1(vector<int>& nums) {
        int one = 0, two = 0, temp;
        for (int n : nums) {
            temp = two;
            two = max(one + n, two);
            one = temp;
        }
        return two;
    }

    int rob(vector<int>& nums) {
        vector<int> nums1 (nums.begin() + 1, nums.end());
        vector<int> nums2 (nums.begin(), nums.end() - 1);
        return max(nums[0], max(rob1(nums1), rob1(nums2)));
    }
};