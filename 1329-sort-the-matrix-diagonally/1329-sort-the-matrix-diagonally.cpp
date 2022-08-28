class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        for (int i = 0, j = 0; j < m; ++j) {
            int x = i, y = j;
            vector<int> v;
            while (x < n && y < m) {
                v.emplace_back(mat[x][y]);
                ++x, ++y;
            }
            sort(v.begin(), v.end());

            x = i, y = j;
            int cnt = 0;
            while (x < n && y < m) {
                mat[x][y] = v[cnt++];
                ++x, ++y;
            }
        }
        
        for (int i = 0, j = 0; i < n; ++i) {
            int x = i, y = j;
            vector<int> v;
            while (x < n && y < m) {
                v.emplace_back(mat[x][y]);
                ++x, ++y;
            }
            sort(v.begin(), v.end());

            x = i, y = j;
            int cnt = 0;
            while (x < n && y < m) {
                mat[x][y] = v[cnt++];
                ++x, ++y;
            }
        }
        return mat;
    }
};