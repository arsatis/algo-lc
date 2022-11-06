class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[10001] = {};
        fill(dp + 1, dp + 10001, 10001);
        for (int i = 1; i <= amount; ++i)
            for (int x : coins)
                if (x <= i) dp[i] = min(dp[i], 1 + dp[i - x]);
        return dp[amount] == 10001 ? -1 : dp[amount];
    }
};
