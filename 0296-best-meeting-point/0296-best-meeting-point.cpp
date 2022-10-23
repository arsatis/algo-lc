class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> xs, ys;
        
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i)
                if (grid[i][j]) xs.emplace_back(j);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) ys.emplace_back(i);
        
        int dist = 0;
        int xmid = xs[xs.size() >> 1];
        for (int x : xs) dist += abs(x - xmid);
        int ymid = ys[ys.size() >> 1];
        for (int y : ys) dist += abs(y - ymid);
        return dist;
    }
};