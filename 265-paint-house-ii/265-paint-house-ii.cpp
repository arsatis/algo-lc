class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int i = 0, k = costs[0].size();
        vector<vector<int>> colors(2, vector<int>(k));
        for (auto& v : costs) {
            for (int j = 0; j < k; ++j) {
                int tmp = colors[i][j];
                colors[i][j] = INT_MAX;
                colors[1 - i][j] = v[j] + *min_element(colors[i].begin(), colors[i].end());
                colors[i][j] = tmp;
            }
            i = 1 - i;
        }
        return *min_element(colors[i].begin(), colors[i].end());
    }
};
