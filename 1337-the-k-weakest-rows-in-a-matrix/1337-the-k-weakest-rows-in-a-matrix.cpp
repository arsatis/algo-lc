class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> v(m);
        for(int i = 0; i < m; ++i){
            int j = 0;
            while(j < n && mat[i][j] == 1){
                j += 1;
            }
            v[i] = make_pair(j, i);
        }
        sort(v.begin(), v.end());
        vector<int> ret(k);
        for(int i = 0; i < k; ++i){
            ret[i] = v[i].second;
        }
        return ret;
    }
};