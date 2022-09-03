class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
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