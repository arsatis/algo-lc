class Solution {
    pair<int, int> dir[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
                             {1, 1}, {1, 0}, {1, -1}, {0, -1}};
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1, pathLen = 1;
        queue<pair<int, int>> q;
        
        if (grid[0][0]) return -1;
        grid[0][0] = 1;
        q.emplace(0, 0);
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                auto [i, j] = q.front();
                if (i == n && j == n) return pathLen;
                q.pop();
                
                for (int k = 0; k < 8; ++k) {
                    int i2 = i + dir[k].first, j2 = j + dir[k].second;
                    if (i2 >= 0 && i2 <= n && j2 >= 0 && j2 <= n && !grid[i2][j2]) {
                        grid[i2][j2] = 1;
                        q.emplace(i2, j2);
                    }
                }
            }
            ++pathLen;
        }
        return -1;
    }
};