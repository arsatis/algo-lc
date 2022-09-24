class Solution {
public:
    int arrangeCoins(int n) {
        return sqrt(((long) n << 1) + 0.25) - 0.5;
    }
};