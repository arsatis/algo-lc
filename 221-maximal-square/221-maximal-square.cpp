class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int dp[matrix.size() + 1][matrix[0].size() + 1];
        int maxSide = 0;
        
        for (int i = 0; i < matrix.size(); ++i) dp[i][0] = 0;
        for (int i = 1; i < matrix[0].size(); ++i) dp[0][i] = 0;
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    dp[i + 1][j + 1] = 1 + min({dp[i][j], dp[i + 1][j], dp[i][j + 1]});
                    maxSide = max(maxSide, dp[i + 1][j + 1]);
                } else {
                    dp[i + 1][j + 1] = 0;
                }
            }
        }
        
        return maxSide * maxSide;
    }
};