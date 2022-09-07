class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int output = 0, n = mat.size();
        for (int i = 0; i < n; ++i)
            output += mat[i][i] + mat[i][n - i - 1];
        if (n % 2) output -= mat[n >> 1][n >> 1];
        return output;
    }
};