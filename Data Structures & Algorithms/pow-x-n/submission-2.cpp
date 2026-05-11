class Solution {
public:
    double myPow(double x, int n) {
        if (!n) return 1;
        double result = 1;
        for (int i = 0; i < abs(n); ++i) result *= x;
        return n > 0 ? result : 1 / result;
    }
};
