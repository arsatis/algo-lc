class Solution {
    int hash(int i, int j) {
        return (i << 4) + j;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<int> fresh;
        queue<pair<int, int>> rotten;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) fresh.insert(hash(i, j));
                if (grid[i][j] == 2) rotten.emplace(i, j);
            }
        }
        
        int iter = rotten.empty() ? 0 : -1;
        while (!rotten.empty()) {
            int s = rotten.size();
            while (s--) {
                int key;
                auto [i, j] = rotten.front();
                rotten.pop();
                
                if (i > 0 && fresh.find(key = hash(i - 1, j)) != fresh.end())
                    fresh.erase(key), rotten.emplace(i - 1, j);
                if (j > 0 && fresh.find(key = hash(i, j - 1)) != fresh.end())
                    fresh.erase(key), rotten.emplace(i, j - 1);
                if (i < m - 1 && fresh.find(key = hash(i + 1, j)) != fresh.end())
                    fresh.erase(key), rotten.emplace(i + 1, j);
                if (j < n - 1 && fresh.find(key = hash(i, j + 1)) != fresh.end())
                    fresh.erase(key), rotten.emplace(i, j + 1);
            }
            ++iter;
        }
        return fresh.empty() ? iter : -1;
    }
};