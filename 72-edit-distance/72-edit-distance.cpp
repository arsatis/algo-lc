class Solution {
    int helper(string word1, int m, string word2, int n) {
        if(m==0)
            return n;//insert all letters
        if(n==0)
            return m; //delete all letters
        
        if(word1[m-1] == word2[n-1])
            return helper(word1, m-1, word2, n-1);
        
        int insert = helper(word1, m, word2, n-1);
        int del = helper(word1, m-1, word2, n);
        int replace = helper(word1, m-1, word2, n-1);
        
        return 1 + min(insert, min(del, replace));
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    int insert = dp[i][j-1];
                    int del = dp[i-1][j];
                    int replace = dp[i-1][j-1];
                
                    dp[i][j] = 1 + min(insert, min(del, replace));
                }
                
            }
        }
        
        return dp[m][n];
    }
};