class Solution {
    int bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        grid2[i][j] = 0;
        bool isSubIsland = grid1[i][j];
        if (i > 0 && grid2[i - 1][j]) isSubIsland &= bfs(grid1, grid2, i - 1, j);
        if (j > 0 && grid2[i][j - 1]) isSubIsland &= bfs(grid1, grid2, i, j - 1);
        if (i < grid2.size() - 1 && grid2[i + 1][j]) isSubIsland &= bfs(grid1, grid2, i + 1, j);
        if (j < grid2[0].size() - 1 && grid2[i][j + 1]) isSubIsland &= bfs(grid1, grid2, i, j + 1);
        return isSubIsland;
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size(), num = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid2[i][j]) num += bfs(grid1, grid2, i, j);
        return num;
    }
};