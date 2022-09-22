class Solution {
    int n;
    vector<int> path;
    vector<vector<int>> paths;
    void dfs(vector<vector<int>>& graph) {
        for (int i : graph[path.back()]) {
            path.emplace_back(i);
            if (i == n) paths.emplace_back(path);
            else dfs(graph);
            path.pop_back();
        }
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size() - 1;
        path.reserve(graph.size());
        path.emplace_back(0);
        dfs(graph);
        return move(paths);
    }
};