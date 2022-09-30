class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int y = 1; y < n; y++)
            for (int x = 0; x < m; x++) {
                int up = y-1 >= 0 ? matrix[y-1][x] : INT_MAX;
                int upLeft = y-1 >= 0 && x-1 >= 0 ? matrix[y-1][x-1] : INT_MAX;
                int upRight = y-1>= 0 && x+1 < m ? matrix[y-1][x+1] : INT_MAX;
                matrix[y][x] = min(up, min(upLeft, upRight)) + matrix[y][x];
            }
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};