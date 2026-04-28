class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (!n) return 0;
        int worst = heights[0];
        for (int i = 1; i < n; ++i) worst = min(heights[i], worst);
        int iworst = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            if (heights[i] == worst) {
                vector sub(heights.begin() + iworst, heights.begin() + i);
                result = max(result, largestRectangleArea(sub));
                iworst = i + 1;
            }
        }
        if (iworst < n) {
            vector sub(heights.begin() + iworst, heights.end());
            result = max(result, largestRectangleArea(sub));
        }
        return max(worst * n, result);
    }
};