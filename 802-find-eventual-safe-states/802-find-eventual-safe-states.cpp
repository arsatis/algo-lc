class Solution {
    vector<int> safe;
    bool dfs(vector<vector<int>>& graph, int i) {
        if (safe[i]) return safe[i] == 1;
        if (graph[i].empty()) {
            safe[i] = 1;
            return true;
        }
        bool isSafe = true;
        safe[i] = -1;
        for (int j : graph[i]) if (!dfs(graph, j)) isSafe = false;
        if (isSafe) safe[i] = 1;
        return isSafe;
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        safe.resize(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i) dfs(graph, i);
        
        vector<int> output;
        for (int i = 0; i < graph.size(); ++i)
            if (safe[i] == 1) output.emplace_back(i);
        return move(output);
    }
};