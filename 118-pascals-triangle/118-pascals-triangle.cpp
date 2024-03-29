class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output(numRows, vector<int>(1, 1));
        for (int i = 1; i < numRows; ++i) {
            output[i].reserve(i);
            for (int j = 1; j < i; ++j)
                output[i].emplace_back(output[i - 1][j - 1] + output[i - 1][j]);
            output[i].emplace_back(1);
        }
        return move(output);
    }
};