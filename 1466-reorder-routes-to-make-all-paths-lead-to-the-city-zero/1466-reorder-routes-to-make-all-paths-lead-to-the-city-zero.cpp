class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<pair<int, bool>> adj[n];
        vector<bool> vis(n);
        for(auto& it: conn) {
            adj[it[0]].push_back({it[1], true});
            adj[it[1]].push_back({it[0], false});
        }
        int ans = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int m = q.size();
            for(int i = 0; i < m; i++) {
                int root = q.front(); q.pop();
                vis[root] = true;
                for(auto& it: adj[root]) {
                    if(vis[it.first]) continue;
                    if(it.second) ans++;
                    q.push(it.first);
                }
            }
        }
        return ans;
    }
};