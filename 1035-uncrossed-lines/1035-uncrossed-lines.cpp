class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int dp[2][501] = {};
        for (int i = 0; i < nums1.size(); ++i)
            for (int j = 0; j < nums2.size(); ++j)
                dp[(i + 1) % 2][j + 1] = max((nums1[i] == nums2[j]) + dp[i % 2][j],
                        max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]));
        return dp[nums1.size() % 2][nums2.size()];
    }
};
