class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (int m = grid.size(), n = grid[0].size(), r = 0, c = n - 1; r < m;) {
            while (c >= 0 && grid[r][c] < 0) --c;
            ans += n - c - 1;
            ++r;
        }
        return ans;
    }
};