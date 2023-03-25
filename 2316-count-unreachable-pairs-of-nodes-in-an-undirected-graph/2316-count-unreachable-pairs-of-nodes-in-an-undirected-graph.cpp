class Solution {
    int par[100000];
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        iota(par, par + n, 0);
        for (auto& edge : edges) {
            int a = find(edge[0]), b = find(edge[1]);
            if (a != b) {
                if (a > b) par[a] = b;
                else par[b] = a;
            }
        }
        
        long long output = 0;
        long k = n, collect[n];
        memset(collect, 0, sizeof(collect));
        for (int i = 0; i < n; ++i) ++collect[find(i)];
        for (int i = 0; i < n; ++i)
            if (collect[i] > 0)
                k -= collect[i], output += collect[i] * k;
        return output;
    }
};
