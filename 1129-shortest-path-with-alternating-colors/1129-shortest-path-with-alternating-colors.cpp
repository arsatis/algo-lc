class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto& v : redEdges) graph[v[0]].push_back({v[1], 0});
        for(auto& v : blueEdges) graph[v[0]].push_back({v[1], 1});
        vector<vector<int>> vis(n, vector<int>(2, 10001));
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        vis[0][0] = 0, vis[0][1] = 0;
        while(!q.empty()){
            auto [i, c1] = q.front(); q.pop();
            for(auto [j, c2] : graph[i]){
                if(vis[j][c2] != 10001 || c1 == c2) continue;
                vis[j][c2] = vis[i][c1] + 1;
                q.push({j, c2});
            }
        }
        vector<int> res;
        for(auto v : vis){
            int val = v[1] > v[0] ? v[0] : v[1];
            res.push_back(val == 10001 ? -1 : val);
        }
        return move(res);
    }
};