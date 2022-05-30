class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == 1 << 31 && divisor == -1)
            return (1 << 31) - 1;
        int a = Math.abs(dividend), b = Math.abs(divisor), quotient = 0, x = 31;
        while (a - b >= 0) {
            if ((a >>> x) - b >= 0) {
                quotient += 1 << x;
                a -= b << x;
            }
            --x;
        }
        return (dividend > 0) == (divisor > 0) ? quotient : -quotient;
    }
}