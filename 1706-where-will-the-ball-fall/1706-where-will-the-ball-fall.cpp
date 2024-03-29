class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> result(grid[0].size());

        for (int i = 0; i < grid[0].size(); ++i) {
            int currentCol = i;
            for (int j = 0; j < grid.size(); ++j) {
                int nextCol = currentCol + grid[j][currentCol];
                if (nextCol < 0 || nextCol > grid[0].size() - 1 ||
                    grid[j][currentCol] != grid[j][nextCol]) {
                    result[i] = -1;
                    break;
                }
                result[i] = nextCol;
                currentCol = nextCol;
            }
        }
        return move(result);
    }
};