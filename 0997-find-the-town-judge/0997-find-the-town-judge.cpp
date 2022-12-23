class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int findJudge(int n, vector<vector<int>>& trust) {
        int arr[(n << 1) + 1];
        memset(arr, 0, sizeof(arr));
        for (auto& v : trust) ++arr[v[0]], ++arr[n + v[1]];
        for (int i = 1; i <= n; ++i) if (!arr[i] && arr[n + i] == n - 1) return i;
        return -1;
    }
};
