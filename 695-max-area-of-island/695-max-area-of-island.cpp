class Solution {
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (!grid[i][j]) return 0;
        grid[i][j] = 0;
        int total = 1;
        if (i > 0) total += dfs(grid, i - 1, j);
        if (j > 0) total += dfs(grid, i, j - 1);
        if (i < grid.size() - 1) total += dfs(grid, i + 1, j);
        if (j < grid[0].size() - 1) total += dfs(grid, i, j + 1);
        return total;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j]) maxArea = max(maxArea, dfs(grid, i, j));
        return maxArea;
    }
};