class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        
        if (m * n != r * c) return mat;
        vector<vector<int>> output(r, vector<int>(c));
        for (int rPtr = 0, mPtr = 0, nPtr = 0; rPtr < r; ++rPtr) {
            for (int cPtr = 0; cPtr < c; ++cPtr) {
                output[rPtr][cPtr] = mat[mPtr][nPtr];
                if (++nPtr >= n) {
                    ++mPtr;
                    nPtr = 0;
                }
            }
        }
        return output;
    }
};