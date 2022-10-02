class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int numRollsToTarget(int n, int k, int target) {
        if (target < n || target > n * k) return 0;
        
        int mod = 1e9 + 7;
        vector<int> dp(target + 1);
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            int total = 0;
            for (int j = max(0, target - k); j <= target; ++j)
                total = (total + dp[j]) % mod;
            for (int j = target; j >= 0; --j) {
                total = (total - dp[j] + mod) % mod;
                dp[j] = total;
                if (j - k - 1 >= 0) total = (total + dp[j - k - 1]) % mod;
            }
        }
        return dp[target];
    }
};
