class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), num = -1;
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) q.emplace(i, j);
        
        if (q.size() == n * n) return -1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                
                if (i > 0 && !grid[i - 1][j]) grid[i - 1][j] = 1, q.emplace(i - 1, j);
                if (j > 0 && !grid[i][j - 1]) grid[i][j - 1] = 1, q.emplace(i, j - 1);
                if (i < n - 1 && !grid[i + 1][j]) grid[i + 1][j] = 1, q.emplace(i + 1, j);
                if (j < n - 1 && !grid[i][j + 1]) grid[i][j + 1] = 1, q.emplace(i, j + 1);
            }
            ++num;
        }
        return num;
    }
};