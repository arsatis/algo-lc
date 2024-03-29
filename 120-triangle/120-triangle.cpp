class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minlen(triangle.back());
        for (int layer = triangle.size() - 2; layer >= 0; --layer)
            for (int i = 0; i <= layer; ++i)
                minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
        return minlen.front();
    }
};