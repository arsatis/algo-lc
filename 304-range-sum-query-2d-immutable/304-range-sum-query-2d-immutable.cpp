class NumMatrix {
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        sums = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                int pi = i - 1, pj = j - 1;
                sums[i][j] = matrix[pi][pj] + sums[pi][j] + sums[i][pj] - sums[pi][pj];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[++row2][++col2] - sums[row2][col1] - sums[row1][col2] + sums[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */