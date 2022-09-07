class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);
        int output = 0, n = mat.size();
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            output += mat[i][i];
            output += mat[i][j];
        }
        if (n % 2) output -= mat[n >> 1][n >> 1];
        return output;
    }
};