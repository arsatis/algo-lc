class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int dp[matrix.size()][matrix[0].size()];
        
        for (int i = 0; i < matrix.size(); ++i) dp[i][0] = matrix[i][0] - '0';
        for (int i = 1; i < matrix[0].size(); ++i) dp[0][i] = matrix[0][i] - '0';
        
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        int maxSide = 0;
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                maxSide = max(maxSide, dp[i][j]);
        
        return maxSide * maxSide;
    }
};