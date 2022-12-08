class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int num = 0, currEnd = INT_MIN;
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) { return x[1] < y[1]; });
        for (auto& i : intervals) {
            if (currEnd <= i[0]) currEnd = i[1];
            else ++num;
        }
        return num;
    }
};
