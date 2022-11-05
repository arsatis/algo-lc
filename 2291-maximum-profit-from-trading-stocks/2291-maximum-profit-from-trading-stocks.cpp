class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int dp[1001] = {};
        for (int i = 0; i < present.size(); ++i) {
            if (future[i] <= present[i]) continue;
            int diff = future[i] - present[i];
            for (int j = budget; j >= present[i]; --j)
                dp[j] = max(dp[j], dp[j - present[i]] + diff);
        }
        return dp[budget];
    }
};
