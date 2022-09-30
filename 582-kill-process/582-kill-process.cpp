class Solution {
    void dfs(vector<int>& killed, unordered_map<int, vector<int>>& adj, int cur){
        killed.push_back(cur);
        for (int next : adj[cur]) dfs(killed, adj, next);
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < pid.size(); ++i)
            if (ppid[i] > 0) adj[ppid[i]].push_back(pid[i]);
        vector<int> killed;
        dfs(killed, adj, kill);
        return killed;
    }
};