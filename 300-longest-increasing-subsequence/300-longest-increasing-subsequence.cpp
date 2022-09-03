class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
        return accumulate(dp.begin(), dp.end(), 1, [](int& x, int& y) {
            return x > y ? x : y;
        });
    }
};