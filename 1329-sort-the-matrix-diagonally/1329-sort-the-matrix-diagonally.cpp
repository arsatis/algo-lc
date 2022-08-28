class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < mat.size(); ++i)
            for (int j = 0; j < mat[0].size(); ++j)
                mp[i - j].push_back(mat[i][j]);

        int m = mat.size();
        for (int k = -(mat[0].size() - 1); k < m; ++k)
            sort(mp[k].begin(), mp[k].end());

        for (int i = mat.size() - 1; i >= 0; --i) {
            for (int j = mat[0].size() - 1; j >= 0; --j) {
                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }
        
        return mat;
    }
};