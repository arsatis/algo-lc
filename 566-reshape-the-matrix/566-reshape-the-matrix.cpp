class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = mat.size() * mat[0].size();
        if (n != r * c) return mat;
        
        vector<vector<int>> output(r, vector<int>(c));
        for (int i = 0; i < n; ++i)
            output[i / c][i % c] = mat[i / mat[0].size()][i % mat[0].size()];
        return output;
    }
};