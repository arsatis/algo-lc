class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int dp[10001] = { 0 };
        for (int n : nums) dp[n] += n;
     
        int x = dp[1];
        for (int i = 2; i <= 10000; ++i) {
            dp[i] = max(dp[i - 1], dp[i] + dp[i - 2]);
            if (dp[i] > x) x = dp[i];
        }
        return x;
    }
};