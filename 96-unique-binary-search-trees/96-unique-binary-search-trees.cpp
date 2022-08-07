class Solution {
public:
    int numTrees(int n) {
        long ans = 1;
        for (int i = 0; i < n; ++i) ans *= ((i << 2) + 2) / (i + 2.); // Catalan numbers
        return ans;
    }
};