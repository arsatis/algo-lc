class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int x = 1, y = 2;
        for (int i = 3; i <= n; ++i) {
            x += y;
            swap(x, y);
        }
        return y;
    }
};