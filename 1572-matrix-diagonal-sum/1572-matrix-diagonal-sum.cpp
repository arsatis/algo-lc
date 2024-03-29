class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i = 0;
        return accumulate(mat.begin(), mat.end(), 0, [&i](int val, auto& v) {
            return val + v[i++] + (i << 1 == v.size() + 1 ? 0 : v[v.size() - i]);
        });
    }
};