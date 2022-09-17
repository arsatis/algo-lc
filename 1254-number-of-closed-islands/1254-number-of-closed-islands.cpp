class Solution {
    int f(vector<vector<int>>& g, int i, int j) {
        int sum = g[i][j] = 1;
        if (i > 0 && !g[i - 1][j]) sum += f(g, i - 1, j);
        if (j > 0 && !g[i][j - 1]) sum += f(g, i, j - 1);
        if (i < g.size() - 1 && !g[i + 1][j]) sum += f(g, i + 1, j);
        if (j < g[0].size() - 1 && !g[i][j + 1]) sum += f(g, i, j + 1);
        return sum;
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int closedIsland(vector<vector<int>>& g) {
        int res = 0;
        for (int i = 0; i < g.size(); ++i)
            for (int j = 0; j < g[i].size(); ++j)
                if ((i * j == 0 || i == g.size() - 1 || j == g[i].size() - 1) && !g[i][j])
                    f(g, i, j);
        for (int i = 0; i < g.size(); ++i)
            for (int j = 0; j < g[i].size(); ++j)
                if (!g[i][j]) res += f(g, i, j) > 0;
        return res;
    }
};