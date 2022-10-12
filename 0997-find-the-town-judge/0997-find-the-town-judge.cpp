class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) return 1;
        vector<int> a(n + 1), b(n + 1);
        for (auto& v : trust) ++a[v.front()], ++b[v.back()];
        for (int i = 0; i <= n; ++i) if (a[i] == 0 && b[i] == n - 1) return i;
        return -1;
    }
};