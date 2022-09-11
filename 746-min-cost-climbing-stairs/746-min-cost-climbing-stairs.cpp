class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() + 1;
        vector<int> dp(n);
        for (int i = 2; i < n; ++i)
            dp[i] = min(cost[i - 2] + dp[i - 2], cost[i - 1] + dp[i - 1]);
        return dp.back();
    }
};