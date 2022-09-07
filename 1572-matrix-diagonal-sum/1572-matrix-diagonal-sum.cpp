class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int output = 0;
        for (int i = 0, j = mat.size() - 1; i < mat.size(); ++i, --j)
            output += mat[i][i] + (i != j ? mat[i][j] : 0);
        return output;
    }
};