class Solution {
public:
    int countHousePlacements(int n) {
        long prev2 = 1, prev1 = 2, mod = 1e9 + 7;
        while (n-- > 1) swap(prev2 = (prev1 + prev2) % mod, prev1);
        return (prev1 * prev1) % mod;
    }
};