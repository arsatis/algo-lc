class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int arrangeCoins(int n) {
        return sqrt(((long) n << 1) + 0.25) - 0.5;
    }
};