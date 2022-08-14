class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& i, auto& j) {
            return i[1] < j[1];
        });
        vector<vector<int>> output;
        for (int i = intervals.size() - 1; i >= 0; --i) {
            if (output.size() == 0 || output.back()[0] > intervals[i][1])
                output.push_back(intervals[i]);
            else
                output.back()[0] = min(output.back()[0], intervals[i][0]);
        }
        reverse(output.begin(), output.end());
        return output;
    }
};