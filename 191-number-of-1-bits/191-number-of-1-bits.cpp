class Solution {
public:
    int hammingWeight(uint32_t n) {
        int weight = 0;
        while (n > 0) {
            weight += 1 & n;
            n >>= 1;
        }
        return weight;
    }
};