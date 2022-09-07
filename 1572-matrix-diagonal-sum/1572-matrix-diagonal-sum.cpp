class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int output = 0;
        for (int i = 0, j = mat.size() - 1; i < mat.size(); ++i, --j)
            output += mat[i][i] + (i != j ? mat[i][j] : 0);
        return output;
    }
};