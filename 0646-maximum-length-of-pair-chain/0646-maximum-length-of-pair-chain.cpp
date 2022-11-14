class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int chain = 0, prev = 1001;
        sort(pairs.begin(), pairs.end(), [](auto& v1, auto& v2) { return v1[0] > v2[0]; });
        for (auto& v : pairs) if (v[1] < prev) ++chain, prev = v[0];
        return chain;
    }
};
