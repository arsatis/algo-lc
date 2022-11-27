class Solution {
public:
    int minDistance(string& word1, string& word2) {
        int dp[2][501] = {};
        for (int j = 1; j <= word2.size(); ++j) dp[0][j] = j;
        for (int i = 0; i < word1.size(); ++i) {
            dp[(i + 1) % 2][0] = i + 1;
            for (int j = 0; j < word2.size(); ++j)
                dp[(i + 1) % 2][j + 1] = word1[i] == word2[j]
                    ? dp[i % 2][j] : 1 + min(dp[i % 2][j + 1], dp[(i + 1) % 2][j]);
        }
        return dp[word1.size() % 2][word2.size()];
    }
};
