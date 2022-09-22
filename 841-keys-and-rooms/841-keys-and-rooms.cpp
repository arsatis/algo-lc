class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int num_visited = 0;
        vector<int> visited(rooms.size());
        queue<int> q;
        
        ++visited[0], ++num_visited, q.emplace(0);
        while (!q.empty()) {
            int next = q.front();
            q.pop();
            for (int room : rooms[next])
                if (!visited[room]) {
                    q.emplace(room); 
                    ++visited[room];
                    ++num_visited;
                }
        }
        return num_visited == rooms.size();
    }
};