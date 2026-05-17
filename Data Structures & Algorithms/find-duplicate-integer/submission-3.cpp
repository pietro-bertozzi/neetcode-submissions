class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int n : nums) {
            int index = abs(n) - 1;
            if (nums[index] < 0) return abs(n);
            nums[index] *= -1;
        }
    }
};
