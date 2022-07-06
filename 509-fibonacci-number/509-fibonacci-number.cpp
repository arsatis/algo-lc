class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        int x = 0, y = 1;
        for (; n > 1; --n) {
            y += x;
            x = y - x;
        }
        return y;
    }
};