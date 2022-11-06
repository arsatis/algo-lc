class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int i = 0, k = costs[0].size(), min1, min2;
        vector<vector<int>> colors(2, vector<int>(k));
        for (auto& v : costs) {
            min1 = INT_MAX, min2 = INT_MAX;
            for (int j = 0; j < k; ++j) {
                if (colors[i][j] < min1) min2 = min1, min1 = colors[i][j];
                else if (colors[i][j] < min2) min2 = colors[i][j];
            }
            for (int j = 0; j < k; ++j)
                colors[1 - i][j] = v[j] + (colors[i][j] == min1 ? min2 : min1);
            i = 1 - i;
        }
        return *min_element(colors[i].begin(), colors[i].end());
    }
};
