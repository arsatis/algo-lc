class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        
        bitset<10001> dp(1);   // 0 is always achievable => dp[0] = 1
        for (int num : nums) dp = dp | dp << num;
        return dp[sum >> 1];
    }
};