class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size());
        queue<int> q;
        
        ++visited[0];
        q.emplace(0);
        while (!q.empty()) {
            int next = q.front();
            q.pop();
            for (int room : rooms[next])
                if (!visited[room]) {
                    q.emplace(room); 
                    ++visited[room];
                }
        }
        return accumulate(visited.begin(), visited.end(), 0) == rooms.size();
    }
};