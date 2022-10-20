class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;
        output.reserve(intervals.size() + 1);
        
        // place all smaller intervals into output
        int i = 0;
        while (i < intervals.size() && intervals[i].back() < newInterval.front()) output.emplace_back(intervals[i++]);
        
        // place new interval into output
        if (i < intervals.size()) output.push_back({min(intervals[i].front(), newInterval.front()), newInterval.back()});
        else output.emplace_back(newInterval);
        
        // extend the end of the new interval if necessary, and place remaining intervals into output
        if (i != intervals.size()) {
            while (i < intervals.size() && intervals[i].front() <= output.back().back())
                output.back().back() = max(output.back().back(), intervals[i++].back());
            while (i < intervals.size()) output.emplace_back(intervals[i++]);
        }
        return move(output);
    }
};