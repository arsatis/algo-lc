class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = triangle.size();
        vector<int> minlen(triangle.back());
        for (int layer = n-2; layer >= 0; --layer)
            for (int i = 0; i <= layer; ++i)
                minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
        return minlen[0];
    }
};