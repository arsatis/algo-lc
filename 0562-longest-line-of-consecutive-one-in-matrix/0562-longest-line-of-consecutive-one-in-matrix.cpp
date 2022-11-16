class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0, f[m][n][4];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) continue;
                f[i][j][0] = 1;
                f[i][j][1] = 1;
                f[i][j][2] = 1;
                f[i][j][3] = 1;
                if (i > 0) f[i][j][0] += f[i - 1][j][0];
                if (j > 0) f[i][j][1] += f[i][j - 1][1];
                if (i > 0 && j > 0) f[i][j][2] += f[i - 1][j - 1][2];
                if (i > 0 && j < n - 1) f[i][j][3] += f[i - 1][j + 1][3];
                res = max(res, f[i][j][0]);
                res = max(res, f[i][j][1]);
                res = max(res, f[i][j][2]);
                res = max(res, f[i][j][3]);
            }
        return res;
    }
};
