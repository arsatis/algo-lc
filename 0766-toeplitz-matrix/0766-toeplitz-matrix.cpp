class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1 - m; i < n; ++i) {
            int tmp = -1;
            for (int j = max(0, -i); j < m && i + j < n; ++j) {
                if (tmp == -1) tmp = matrix[j][i + j];
                else if (tmp != matrix[j][i + j]) return false;
            }
        }
        return true;
    }
};