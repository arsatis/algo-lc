
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, int> color;
        vector<vector<int>> adjlist(n + 1);
        for (int i = 0; i <= n; ++i) adjlist[i].reserve(n + 1);
        for (auto& d : dislikes) {
            adjlist[d[0]].emplace_back(d[1]);
            adjlist[d[1]].emplace_back(d[0]);
        }
        
        for (int i = 1; i <= n; ++i) {
            queue<int> q;
            q.emplace(i);
            color.insert({i, 0});
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int j : adjlist[node]) {
                    int altColor = color[node] ^ 1;
                    if (color.find(j) == color.end()) color.insert({j, altColor});
                    else if (color[j] == altColor) continue;
                    else return false;
                    q.emplace(j);
                }
            }
        }
        return true;
    }
};