class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        /*
         * High-level idea:
         * - hashmap containing prereqs -> courses requiring this prereq
         * - arr containing number of prereqs each course has
         * "bfs": for each course without a prereq, mark them as read, and traverse courses requiring this prereq if all the prereqs of that course have been read
         */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            ++degree[p[0]];
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) if (degree[i] == 0) q.push(i);
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            --n;
            for (auto& next : adj[curr]) if (--degree[next] == 0) q.push(next);
        }
        
        return n == 0;
    }
};