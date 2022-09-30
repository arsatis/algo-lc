class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> children;
        for (int i = 0; i < ppid.size(); ++i) children[ppid[i]].emplace_back(pid[i]);
            
        vector<int> killed;
        queue<int> q;
        q.emplace(kill);
        while (!q.empty()) {
            int process = q.front();
            killed.emplace_back(process);
            for (int i : children[process]) q.emplace(i);
            q.pop();
        }
        return move(killed);
    }
};