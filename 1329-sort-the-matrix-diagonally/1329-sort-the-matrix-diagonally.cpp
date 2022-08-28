class Solution {
public:
    void f(int m, int n, int i, int j, vector<vector<int>>& mat) {
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
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        for (int i = 0, j = 0; j < mat[0].size(); ++j)
            f(mat[0].size(), mat.size(), i, j, mat);
        for (int i = 0, j = 0; i < mat.size(); ++i)
            f(mat[0].size(), mat.size(), i, j, mat);
        return mat;
    }
};