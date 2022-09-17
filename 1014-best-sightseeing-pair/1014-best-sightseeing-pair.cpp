class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0, imax = 0;
        for (int i = 0; i < values.size(); ++i) {
            res = max(res, imax + values[i] - i);
            imax = max(imax, values[i] + i);
        }
        return res;
    }
};