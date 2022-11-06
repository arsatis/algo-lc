class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1) return k;
        vector<int> numWays(n + 1);
        numWays[1] = k, numWays[2] = k * k;
        for (int i = 3; i <= n; ++i)
            numWays[i] = (numWays[i - 1] + numWays[i - 2]) * (k - 1);
        return numWays[n];
    }
};
