class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<int> numSoldiers(m);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                numSoldiers[i] += mat[i][j];
        
        vector<vector<int>> srMap(n + 1);
        for (int i = 0; i < m; ++i) srMap[numSoldiers[i]].emplace_back(i);
        
        int idx = 0, srOuterIdx = 0, srInnerIdx = 0;
        vector<int> weakest(k);
        while (idx < k) {
            if (srInnerIdx == srMap[srOuterIdx].size()) srInnerIdx = 0, ++srOuterIdx;
            while (srMap[srOuterIdx].empty()) ++srOuterIdx;
            weakest[idx++] = srMap[srOuterIdx][srInnerIdx++];
        }
        return move(weakest);
    }
};