class Solution {
public:
    int sumOfSquares(int n) {
        int result = 0;
        while (n) {
            result += (n % 10) * (n % 10);
            n /= 10;
        }
        return result;
    }

    bool isHappy(int n) {
        int slow = n, fast = sumOfSquares(n);
        int todo = 1, lam = 1;
        while (slow != fast) {
            if (lam == todo) {
                slow = fast;
                todo *= 2;
                lam = 0;
            }
            lam++;
            fast = sumOfSquares(fast);
        }
        return fast == 1;
    }
};