class Solution {
    bool isSquare(int n) {
        int sq = sqrt(n);
        return n == sq * sq;
    }
public:
    int numSquares(int n) {
        while (n % 4 == 0) n >>= 2;
        if (n % 8 == 7) return 4;
        if (isSquare(n)) return 1;
        for (int i = 1; i * i <= n; ++i) if (isSquare(n - i * i)) return 2;
        return 3;
    }
};