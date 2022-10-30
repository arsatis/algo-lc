class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        if (n == 1 && m == 1) return 0;
        
        vector<vector<int>> vis(n, vector<int> (m, -1));
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        auto check = [&](int x, int y) { return x > -1 && x < n && y > -1 && y < m; };

        queue<tuple<int, int, int, int>> q;
        q.emplace(0, 0, 0, k); // {row, col, no: of towns visited, coins left}
        vis[0][0] = k;
        
        while (!q.empty()) {
            auto [row, col, towns, coins] = q.front();
            q.pop();
            if (row == n - 1 && col == m - 1) return towns;
            coins -= grid[row][col];
            for (auto [dx, dy] : dir) {
                int x = row + dx, y = col + dy;
                if (check(x, y) && (vis[x][y] < coins)) {
                    vis[x][y] = coins;
                    q.emplace(x, y, towns + 1, coins);
                }
            }
        }
        return -1;
    }
};