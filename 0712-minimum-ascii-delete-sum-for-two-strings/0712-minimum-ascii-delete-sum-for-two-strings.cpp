class Solution {
public:
    int minimumDeleteSum(string& s1, string& s2) {
        int** dp = new int*[s1.size() + 1];
        for (int i = 0; i <= s1.size(); ++i) dp[i] = new int[s2.size() + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= s1.size(); ++i) dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int i = 1; i <= s2.size(); ++i) dp[0][i] = dp[0][i - 1] + s2[i - 1];
        for (int i = 0; i < s1.size(); ++i)
            for (int j = 0; j < s2.size(); ++j)
                if (s1[i] == s2[j]) dp[i + 1][j + 1] = dp[i][j];
                else dp[i + 1][j + 1] = min(s1[i] + dp[i][j + 1], s2[j] + dp[i + 1][j]);
        return dp[s1.size()][s2.size()];
    }
};
