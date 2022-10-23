class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int minTotalDistance(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();;
        if (0 == row) return 0;
        
        int total = 0;
        vector<int> posR, posC;
        for (int i = 0; i < row; ++i) 
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    posR.emplace_back(i);
                    posC.emplace_back(j);
                }
            }
        
        int med1 = posR[posR.size() >> 1];
        nth_element(posC.begin(), posC.begin() + (posC.size() >> 1), posC.end());
        int med2 = posC[posC.size() >> 1];
        for (auto pos1 : posR) total += abs(pos1 - med1);
        for (auto pos2 : posC) total += abs(pos2 - med2);
        return total;
    }
};