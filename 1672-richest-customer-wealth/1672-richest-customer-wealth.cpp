class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int output = 0;
        for (auto& acc : accounts) output = max(output, accumulate(acc.begin(), acc.end(), 0));
        return output;
    }
};