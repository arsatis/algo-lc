class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n);
        for (auto& edge : edges) ++in[edge.back()];
        
        vector<int> output;
        output.reserve(n);
        for (int i = 0; i < n; ++i) if (!in[i]) output.emplace_back(i);
        return move(output);
    }
};