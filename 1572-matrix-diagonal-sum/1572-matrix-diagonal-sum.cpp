class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);
        int i = 0;
        int ret = accumulate(mat.begin(), mat.end(), 0, [&i](int val, auto& v) {
            return val + v[i++] + v[v.size() - i];
        });
        return mat.size() % 2 ? ret - mat[i >> 1][i >> 1] : ret;
    }
};