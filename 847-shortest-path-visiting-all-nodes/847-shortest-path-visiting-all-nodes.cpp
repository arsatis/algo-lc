class Solution {
    class Tuple {
    public:
        int node, path, cost;
        Tuple(int node, int path, int cost) : node(node), path(path), cost(cost) {}
    };
    bool seen[1 << 12][12];
public:
    int shortestPathLength(vector<vector<int>>& g) {
        queue<Tuple> q;
        
        for (int i = 0; i < g.size(); ++i) {
            int temp = 1 << i;
            Tuple t(i, temp, 1);
            q.emplace(t);
            seen[1 << i][i] = true;
        }
        while (!q.empty()) {
            Tuple cur = q.front();
            q.pop();
            if (cur.path == (1 << g.size()) - 1) return cur.cost - 1;
            for (int x : g[cur.node]){
                int nextpath = cur.path | (1 << x);
                Tuple t(x ,nextpath, cur.cost + 1);
                if (!seen[nextpath][x]) {
                    q.emplace(t);
                    seen[nextpath][x] = true;
                }
            }
        }
        return -1;
    }
};