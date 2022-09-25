class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<unordered_set<int>> dirEdges(n), undirEdges(n);
        for (auto& v : connections) {
            dirEdges[v[0]].insert(v[1]);
            undirEdges[v[0]].insert(v[1]);
            undirEdges[v[1]].insert(v[0]);
        }
        
        int num = -1;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [prev, curr] = q.front();
            q.pop();
            if (dirEdges[curr].find(prev) == dirEdges[curr].end()) ++num;
            for (int next : undirEdges[curr]) if (next != prev) q.emplace(curr, next);
        }
        return num;
    }
};