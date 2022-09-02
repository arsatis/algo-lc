class Solution {
public:
    int hammingWeight(uint32_t n) {
        ios_base::sync_with_stdio(0);

        int weight = 0;
        while (n > 0) {
            weight += 1 & n;
            n >>= 1;
        }
        return weight;
    }
};