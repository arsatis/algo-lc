class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        bitset<10001> dp(1);
        
        // find all possible subset sums: each idx rep. a subset sum = idx is possible
        for (int num : nums) dp = dp | dp << num;
        return dp[sum >> 1];
    }
};