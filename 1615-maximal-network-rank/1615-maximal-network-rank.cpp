class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> neighbours(n);
        for (auto& road : roads) {
            neighbours[road.front()].insert(road.back());
            neighbours[road.back()].insert(road.front());
        }
        
        int maxRank = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                int currRank = neighbours[i].size() + neighbours[j].size() -
                    (neighbours[i].find(j) == neighbours[i].end() ? 0 : 1);
                maxRank = max(maxRank, currRank);
            }
        return maxRank;
    }
};