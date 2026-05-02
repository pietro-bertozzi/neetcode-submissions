class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 2;
        for (int i = 2; i < n; ++i) {
            if (i % 2) two += one;
            else one += two; 
        }
        return n % 2 ? one : two;
    }
};
