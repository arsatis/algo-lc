class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> output;
        output.reserve(intervals.size());
        for (auto& v : intervals) {
            if (v[0] < toBeRemoved[0]) output.emplace_back(vector<int>{v[0], min(v[1], toBeRemoved[0])});
            if (v[1] > toBeRemoved[1]) output.emplace_back(vector<int>{max(v[0], toBeRemoved[1]), v[1]});
        }
        return move(output);
    }
};