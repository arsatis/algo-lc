class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        int matrix[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == '0') matrix[i][j] = 0;
                else {
                    ans = 1;
                    matrix[i][j] = 1;
                }
            }
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) continue;
                matrix[i][j] += min(matrix[i - 1][j - 1],
                                min(matrix[i][j - 1], matrix[i - 1][j]));
                ans = max(ans, matrix[i][j] * matrix[i][j]);
            }
        return ans;
    }
};