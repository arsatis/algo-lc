class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, 0));
        memo[0][0] = 1;
        
        for (int dice = 1; dice <= n; ++dice) {
            for (int rem = 0; rem <= target; ++rem) {
                int numWays = 0;
                for (int i = 1; i <= min(k, rem); ++i)
                    numWays = (numWays + memo[dice - 1][rem - i]) % mod;
                memo[dice][rem] = numWays;
            }
        }
        return memo[n][target];
    }
};