class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        
        for (int i = 1; i <= target; ++i) {
            for (int j : nums) {
                if (i < j) continue;
                else dp[i] += dp[i - j];
            }
        }
        return dp[target];
    }
};