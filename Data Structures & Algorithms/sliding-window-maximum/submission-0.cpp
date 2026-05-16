class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            if (!(i % k)) left[i] = nums[i];
            else left[i] = max(left[i - 1], nums[i]);
            if (!((n - 1 - i) % k)) right[n - 1 - i] = nums[n - 1 - i];
            else right[n - 1 - i] = max(right[n - i], nums[n - 1 - i]);
        }
        vector<int> result(n - k + 1);
        for (int i = 0; i < n - k + 1; i++) result[i] = max(left[i + k - 1], right[i]);
        return result;
    }
};