class Solution {
    int visited[200] = { 0 };
    void dfs(vector<vector<int>>& mat, int i) {
        visited[i] = 1;
        for (int j = 0; j < mat.size(); ++j)
            if (mat[i][j] && !visited[j])
                dfs(mat, j);
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), num = 0;
        for (int i = 0; i < n; ++i) isConnected[i][i] = 0;
        for (int i = 0; i < n; ++i)
            if (!visited[i])
                dfs(isConnected, i), ++num;
        return num;
    }
};