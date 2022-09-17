class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0, cur = 0;
        for (int i : values) {
            res = max(res, cur + i);
            cur = max(cur, i) - 1;
        }
        return res;
    }
};