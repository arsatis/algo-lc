class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int i = 0;
        vector<vector<int>> colors(2, vector<int>(3));
        for (auto& v : costs) {
            colors[1 - i][0] = v[0] + min(colors[i][1], colors[i][2]);
            colors[1 - i][1] = v[1] + min(colors[i][0], colors[i][2]);
            colors[1 - i][2] = v[2] + min(colors[i][0], colors[i][1]);
            i = 1 - i;
        }
        return *min_element(colors[i].begin(), colors[i].end());
    }
};
