class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& i, auto& j) {
            return i.back() < j.back();
        });
        vector<vector<int>> output;
        output.reserve(intervals.size());
        for (int i = intervals.size() - 1; i >= 0; --i) {
            if (output.size() == 0 || output.back().front() > intervals[i].back()) output.emplace_back(intervals[i]);
            else output.back().front() = min(output.back().front(), intervals[i].front());
        }
        return move(output);
    }
};