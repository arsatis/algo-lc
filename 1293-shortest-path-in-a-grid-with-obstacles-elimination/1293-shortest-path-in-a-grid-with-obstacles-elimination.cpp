class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int steps = 1, m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 0;
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto check = [&](int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; };
        
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, k);
        visited[0][0] = k;
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j, pwr] = q.front();
                q.pop();
                for (auto [di, dj] : directions) {
                    int _i = i + di, _j = j + dj, _pwr;
                    if (check(_i, _j) && (_pwr = pwr - grid[_i][_j]) >= 0) {
                        if (_i == m - 1 && _j == n - 1) return steps;
                        if (visited[_i][_j] < _pwr) {
                            visited[_i][_j] = _pwr;
                            q.emplace(_i, _j, _pwr);
                        }
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};