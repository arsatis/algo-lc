class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(0);
        
        int num = 0;
        vector<int> prev = { 0, INT_MIN };
        
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {
            return x[1] < y[1];
        });
        for (auto& i : intervals) {
            if (prev[1] <= i[0]) prev = i;
            else ++num;
        }
        
        return num;
    }
};