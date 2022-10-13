
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n, vector<int>());
        for (vector<int>& d : dislikes) {
            adj[d[0]-1].push_back(d[1]-1);
            adj[d[1]-1].push_back(d[0]-1);
        }
        
        vector<int> group(n);
        for (int p = 0; p < n; ++p) {
            if (group[p] == 0) {
                group[p] = 1;
                deque<int> q = {p};
                while (!q.empty()) {
                    int a = q.back();
                    q.pop_back();
                    for (int b : adj[a]) {
                        if (group[b] == 0) {
                            group[b] = group[a] % 2 + 1;
                            q.push_front(b);
                        }
                        else if (group[a] == group[b]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};