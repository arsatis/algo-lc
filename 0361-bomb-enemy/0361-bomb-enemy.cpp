class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0, rowHits = 0, colHits[500];
        memset(colHits, 0, sizeof(colHits));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // check row
                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowHits = 0;
                    for (int k = j; k < n; ++k) {
                        if (grid[i][k] == 'W') break;
                        else if (grid[i][k] == 'E') ++rowHits;
                    }
                }

                // check col
                if (i == 0 || grid[i - 1][j] == 'W') {
                    colHits[j] = 0;
                    for (int k = i; k < m; ++k) {
                        if (grid[k][j] == 'W') break;
                        else if (grid[k][j] == 'E') ++colHits[j];
                    }
                }

                if (grid[i][j] == '0') res = max(res, rowHits + colHits[j]);
            }
        }
        return res;
    }
};
