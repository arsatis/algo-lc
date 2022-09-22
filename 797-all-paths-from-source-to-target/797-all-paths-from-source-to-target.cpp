class Solution {
    vector<int> path;
    vector<vector<int>> paths;
    void dfs(vector<vector<int>>& graph) {
        for (int i : graph[path.back()]) {
            path.emplace_back(i);
            if (i == graph.size() - 1) paths.emplace_back(path);
            else dfs(graph);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.emplace_back(0);
        dfs(graph);
        return move(paths);
    }
};