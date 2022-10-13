class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> neighbours(n, vector<int>(n));
        vector<int> numNeighbours(n);
        for (auto& road : roads) {
            ++neighbours[road.front()][road.back()];
            ++neighbours[road.back()][road.front()];
            ++numNeighbours[road.front()];
            ++numNeighbours[road.back()];
        }
        
        int maxRank = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                int currRank = numNeighbours[i] + numNeighbours[j] - neighbours[i][j];
                maxRank = max(maxRank, currRank);
            }
        return maxRank;
    }
};