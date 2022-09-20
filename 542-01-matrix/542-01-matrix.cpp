class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
                
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    mat[i][j] = INT_MAX - 1;
                    if (i > 0) mat[i][j] = min(mat[i][j], 1 + mat[i - 1][j]);
                    if (j > 0) mat[i][j] = min(mat[i][j], 1 + mat[i][j - 1]);
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (mat[i][j]) {
                    if (i < m - 1) mat[i][j] = min(mat[i][j], 1 + mat[i + 1][j]);
                    if (j < n - 1) mat[i][j] = min(mat[i][j], 1 + mat[i][j + 1]);
                }
            }
        }
        return move(mat);
    }
};