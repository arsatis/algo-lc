class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0, b = sqrt(c) + 1;
        while (a <= b) {
            long sumOfSquares = (long) a * a + (long) b * b;
            if (sumOfSquares == c) return true;
            else if (sumOfSquares < c) ++a;
            else --b;
        }
        return false;
    }
};