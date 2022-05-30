class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) return 1;
            else return 0;
        }
        
        if (dividend == INT_MIN) {
            if (divisor == -1) return INT_MAX;
            if (divisor > 0)
                return -1 + divide(dividend + divisor, divisor);
            else if (divisor < 0)
                return 1 + divide(dividend - divisor, divisor);
        }
        
        int a = abs(dividend), b = abs(divisor), quotient = 0;
        int x = 31;
        while (a >= b) {
            if ((a >> x) - b >= 0) {
                quotient += 1 << x;
                a -= b << x;
            }
            --x;
        }
        return (dividend > 0) == (divisor > 0) ? quotient : -quotient;
    }
};