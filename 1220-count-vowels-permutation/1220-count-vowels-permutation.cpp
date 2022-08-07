class Solution {
public:
    int countVowelPermutation(int n) {
        if (n == 1) return 5;
        int mod = 1e9 + 7, i = 0;
        long dp[2][5];
        for (int j = 0; j < 5; ++j) dp[i][j] = 1;
        for (int j = 0; j < n - 1; ++j) {
            dp[1 - i][0] = (dp[i][1] + dp[i][2] + dp[i][4]) % mod;
            dp[1 - i][1] = (dp[i][0] + dp[i][2]) % mod;
            dp[1 - i][2] = (dp[i][1] + dp[i][3]) % mod;
            dp[1 - i][3] = dp[i][2] % mod;
            dp[1 - i][4] = (dp[i][2] + dp[i][3]) % mod;
            i = 1 - i;
        }
        for (int j = 1; j < 5; ++j) dp[i][0] += dp[i][j];
        return dp[i][0] % mod;
    }
};