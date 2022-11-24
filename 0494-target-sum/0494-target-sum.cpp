class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        target += sum;
        if (target & 1 || target < 0) return 0;
        target >>= 1;
        
        int dp[10001] = {1};
        int cur = 0;
        for (int num : nums) {
            cur += num;
            for (int i = min(cur, target); i - num >= 0; --i) {
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};
