class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int maxTime = 0;
        vector<vector<int>> subord(n);
        queue<pair<int, int>> q;
        
        q.emplace(headID, 0);
        for (int i = 0; i < n; ++i)
            if (i != headID) subord[manager[i]].emplace_back(i);
        while (!q.empty()) {
            auto [id, time] = q.front();
            q.pop();
            if (time > maxTime) maxTime = time;
            for (int subID : subord[id]) q.emplace(subID, time + informTime[id]);
        }
        return maxTime;
    }
};