class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || z <= (long long) x + y && z % gcd(x, y) == 0;
    }
};