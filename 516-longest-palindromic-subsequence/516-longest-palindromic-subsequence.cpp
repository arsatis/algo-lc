class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string str;
        str.assign(s.rbegin(), s.rend());
        if (str == s) return n;
        if(s.length() == 1) return 1;
        
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = n-2; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1]+2;
                else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};