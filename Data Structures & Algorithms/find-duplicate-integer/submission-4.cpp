class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            int count = 0;
            for (int n : nums) if (n <= m) count++;
            if (count <= m) l = m + 1;
            else r = m;
        }
        return l;
    }
};
