class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size() - 1, rotations = 4;
        bool clockwise[rotations];
        memset(clockwise, true, rotations);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (mat[i][j] != target[i][j]) clockwise[0] = false;
                if (mat[i][j] != target[j][n - i]) clockwise[1] = false;
                if (mat[i][j] != target[n - i][n - j]) clockwise[2] = false;
                if (mat[i][j] != target[n - j][i]) clockwise[3] = false;
            }
        }
        return accumulate(clockwise, clockwise + rotations, false, logical_or<bool>());
    }
};