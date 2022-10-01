class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        vector<int> rows(m), cols(n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (picture[i][j] == 'B') ++rows[i], ++cols[j];
        
        int num = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) ++num;
        return num;
    }
};