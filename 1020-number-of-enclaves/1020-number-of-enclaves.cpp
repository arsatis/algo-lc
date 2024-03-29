class Solution {
    int dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 0;
        int num = 1;
        if (i > 0 && grid[i - 1][j]) num += dfs(grid, i - 1, j);
        if (j > 0 && grid[i][j - 1]) num += dfs(grid, i, j - 1);
        if (i < grid.size() - 1 && grid[i + 1][j]) num += dfs(grid, i + 1, j);
        if (j < grid[0].size() - 1 && grid[i][j + 1]) num += dfs(grid, i, j + 1);
        return num;
    }
    
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), num = 0;
        for (int i = 0; i < m; ++i) {
            if (grid[i][0]) dfs(grid, i, 0);
            if (grid[i][n - 1]) dfs(grid, i, n - 1);
        }
        for (int j = 1; j < n - 1; ++j) {
            if (grid[0][j]) dfs(grid, 0, j);
            if (grid[m - 1][j]) dfs(grid, m - 1, j);
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) num += dfs(grid, i, j);
        return num;
    }
};