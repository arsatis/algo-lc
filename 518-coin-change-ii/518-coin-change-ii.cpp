class Solution {
public:
    int change(int t, vector<int>& coins) {
        int dp[5001] = { 1 };
        for (int c : coins) for (int j = c; j <= t; ++j) dp[j] += dp[j - c];
        return dp[t];
    }
};