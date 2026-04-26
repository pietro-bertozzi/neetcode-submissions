class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0, l = 0, r = height.size() - 1;
        int maxl = height[l], maxr = height[r];
        while (l < r) {
            if (maxl < maxr) {
                maxl = max(height[++l], maxl);
                result += maxl > height[l] ? maxl - height[l] : 0;
            } else {
                maxr = max(height[--r], maxr);
                result += maxr > height[r] ? maxr - height[r] : 0;
            }
        }
        return result;
    }
};