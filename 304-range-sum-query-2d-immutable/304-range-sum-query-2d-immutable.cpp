class NumMatrix {
    vector<vector<int>> vvi;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size() + 1, col = matrix[0].size() + 1;
        vvi.reserve(row);
        vvi.push_back(vector<int>(col, 0));
        for (int i = 1; i < row; ++i) {
            vector<int> vi;
            vi.reserve(col);
            vi.push_back(0);
            for (int j = 1; j < col; ++j) {
                int pi = i - 1, pj = j - 1;
                vi.push_back(matrix[pi][pj] + vvi[pi][j] + vi[pj] - vvi[pi][pj]);
            }
            vvi.push_back(vi);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return vvi[++row2][++col2] - vvi[row2][col1] - vvi[row1][col2] + vvi[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */