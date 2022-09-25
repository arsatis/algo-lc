class Solution {
    vector<int> visited;
    vector<vector<int>> links;
    void dfs(int i) {
        visited[i] = 1;
        for (int j : links[i]) if (!visited[j]) dfs(j);
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        
        int num = 0;
        visited.resize(n, 0);
        links.resize(n, vector<int>());
        
        for (auto& v : connections) {
            links[v[0]].emplace_back(v[1]);
            links[v[1]].emplace_back(v[0]);
        }
        for (int i = 0; i < n; ++i) if (!visited[i]) dfs(i), ++num;
        return num - 1;
    }
};