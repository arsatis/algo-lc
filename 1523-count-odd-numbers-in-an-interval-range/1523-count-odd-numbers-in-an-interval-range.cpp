class Solution {
public:
    int countOdds(int low, int high) {
        ios_base::sync_with_stdio(0);
        return ((high - low) >> 1) + ((low % 2) | (high % 2));
    }
};