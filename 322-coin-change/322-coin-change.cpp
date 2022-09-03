class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; ++i) {
            int val = INT_MAX;
            for (int c : coins)
                if (c <= i && dp[i - c] != -1)
                    val = min(val, 1 + dp[i - c]);
            if (val != INT_MAX) dp[i] = val;
        }
        return dp[amount];
    }
};