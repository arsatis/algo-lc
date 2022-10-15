class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum >> 1;
        vector<bool> dp(subSetSum + 1);
        dp[0] = true;
        for (int curr : nums) {
            for (int j = subSetSum; j >= curr; --j) {
                dp[j] = dp[j] || dp[j - curr];
            }
        }
        return dp[subSetSum];
    }
};