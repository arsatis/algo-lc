class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(n)); // dp[i][j] := # of subseqs end w/ nums[j] nums[i]
        unordered_map<long, vector<int>> numToIndices;

        for (int i = 0; i < n; ++i) numToIndices[nums[i]].push_back(i);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j) {
                long target = nums[j] * 2L - nums[i];
                if (numToIndices.count(target))
                    for (const int k : numToIndices[target])
                        if (k < j) dp[i][j] += (dp[j][k] + 1);
                ans += dp[i][j];
            }
        return ans;
    }
};
