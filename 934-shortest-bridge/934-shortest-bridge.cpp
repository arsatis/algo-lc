class Solution {
    queue<pair<int, int>> q;
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size() - 1;
        
        q.emplace(i, j);
        if (i > 0 && grid[i - 1][j] == 1) ++grid[i - 1][j], dfs(grid, i - 1, j);
        if (j > 0 && grid[i][j - 1] == 1) ++grid[i][j - 1], dfs(grid, i, j - 1);
        if (i < n && grid[i + 1][j] == 1) ++grid[i + 1][j], dfs(grid, i + 1, j);
        if (j < n && grid[i][j + 1] == 1) ++grid[i][j + 1], dfs(grid, i, j + 1);
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), numFlips = 0;
        
        // find first island
        for (int i = 0, j = 0; i < n * n; ++i) {
            if (i == n) { i = 0; ++j; }
            if (grid[i][j]) {
                ++grid[i][j], dfs(grid, i, j);
                break;
            }
        }
        
        // find path to second island
        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                
                if (i > 0 && grid[i - 1][j] != 2) {
                    if (grid[i - 1][j] == 1) return numFlips;
                    grid[i - 1][j] = 2;
                    q.emplace(i - 1, j);
                }
                if (j > 0 && grid[i][j - 1] != 2) {
                    if (grid[i][j - 1] == 1) return numFlips;
                    grid[i][j - 1] = 2;
                    q.emplace(i, j - 1);
                }
                if (i < n - 1 && grid[i + 1][j] != 2) {
                    if (grid[i + 1][j] == 1) return numFlips;
                    grid[i + 1][j] = 2;
                    q.emplace(i + 1, j);
                }
                if (j < n - 1 && grid[i][j + 1] != 2) {
                    if (grid[i][j + 1] == 1) return numFlips;
                    grid[i][j + 1] = 2;
                    q.emplace(i, j + 1);
                }
            }
            ++numFlips;
        }
        return numFlips;
    }
};