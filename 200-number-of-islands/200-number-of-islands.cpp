class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(0);
        
        int num = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                num += bfs(grid, i, j);
        return num;
    }
    
    int bfs(vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '0') return 0;
        grid[i][j] = '0';
        if (i > 0) bfs(grid, i - 1, j);
        if (i < grid.size() - 1) bfs(grid, i + 1, j);
        if (j > 0) bfs(grid, i, j - 1);
        if (j < grid[0].size() - 1) bfs(grid, i, j + 1);
        return 1;
    }
};