#define maxLen 10001

class Solution {
    const int K = 10001;
    void dfs(vector<vector<int>>& stones, vector<int> adj[], vector<int>& visited, int src) {
        visited[src] = 1;
        for (int adjacent : adj[src]) {
            if (visited[adjacent] == 0) {
                dfs(stones, adj, visited, adjacent);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<int> adj[2 * K + 1];
        for (int i = 0; i < stones.size(); ++i) {
            int x = stones[i][0];
            int y = stones[i][1] + K;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        vector<int> visited(2 * K + 1);
        int componentCount = 0;
        for (int i = 0; i < 2 * K + 1; i++) {
            if (visited[i] == 0 && adj[i].size() > 0) {
                ++componentCount;
                dfs(stones, adj, visited, i);
            }
        }
        return stones.size() - componentCount;
    }
};