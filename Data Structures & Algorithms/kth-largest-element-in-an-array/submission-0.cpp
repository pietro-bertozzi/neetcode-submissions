class Solution {
public:
    pair<int, int> partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low;
        for (int j = low; j < high; ++j) {
            if (nums[j] < pivot) {
                swap(nums[j], nums[i++]);
            }
        }
        swap(nums[high], nums[i]);
        return {i, pivot};
    }

    int quickSelect(vector<int>& nums, int low, int high, int k) {
        pair<int, int> index_and_pivot = partition(nums, low, high);
        int index = index_and_pivot.first;
        int pivot = index_and_pivot.second;
        if (index > k) return quickSelect(nums, low, index - 1, k);
        else if (index < k) return quickSelect(nums, index + 1, high, k);
        else return pivot;
    }

    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};
