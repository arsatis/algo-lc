class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int nthUglyNumber(int n) {
        int dp[n + 1];
        dp[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int n2 = 0, n3 = 0, n5 = 0;
        for (int i = 1; i < n; ++i) {
            n2 = dp[i2] * 2;
            n3 = dp[i3] * 3;
            n5 = dp[i5] * 5;
            int j = min(n2, min(n3, n5));
            if (j == n2) ++i2, dp[i] = n2;
            if (j == n3) ++i3, dp[i] = n3;
            if (j == n5) ++i5, dp[i] = n5;
        }
        return dp[n - 1];
    }
};