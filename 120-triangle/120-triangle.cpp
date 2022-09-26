class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minlen(triangle.back());
        for (int layer = triangle.size() - 2; layer >= 0; --layer)
            for (int i = 0; i <= layer; ++i)
                minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
        return minlen.front();
    }
};