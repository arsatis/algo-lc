class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    bool judgeSquareSum(int c) {
        for (long a = 0, sq; (sq = a * a) <= c; ++a) {
            double b = sqrt(c - sq);
            if (b == (int) b) return true;
        }
        return false;
    }
};

// Solution 1: two pointers, O(c)
// bool judgeSquareSum(int c) {
//     int a = 0, b = sqrt(c) + 1;
//     while (a <= b) {
//         long sumOfSquares = (long) a * a + (long) b * b;
//         if (sumOfSquares == c) return true;
//         else if (sumOfSquares < c) ++a;
//         else --b;
//     }
//     return false;
// }

// Solution 2: sqrt, O(sqrt(c)log c)
// bool judgeSquareSum(int c) {
//     for (long a = 0, sq; (sq = a * a) <= c; ++a) {
//         double b = sqrt(c - sq);
//         if (b == (int) b) return true;
//     }
//     return false;
// }