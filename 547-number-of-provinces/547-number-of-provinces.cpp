class Solution {
    unordered_set<int> visited;
    void dfs(vector<vector<int>>& mat, int i) {
        visited.insert(i);
        for (int j = 0; j < mat.size(); ++j)
            if (mat[i][j] && visited.find(j) == visited.end())
                dfs(mat, j);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), num = 0;
        
        for (int i = 0; i < n; ++i) isConnected[i][i] = 0;
        for (int i = 0; i < n; ++i)
            if (visited.find(i) == visited.end())
                dfs(isConnected, i), ++num;
        return num;
    }
};