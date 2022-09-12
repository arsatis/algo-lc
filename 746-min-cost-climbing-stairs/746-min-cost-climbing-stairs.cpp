class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[3] = { 0 };
        for (int i = 2; i < cost.size() + 1; ++i)
            dp[i % 3] = min(dp[(i - 2) % 3] + cost[i - 2],
                            dp[(i - 1) % 3] + cost[i - 1]);
        return dp[cost.size() % 3];
    }
};