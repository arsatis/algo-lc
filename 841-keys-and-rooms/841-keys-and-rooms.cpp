class Solution {
    void dfs(vector<vector<int>>& rooms, int currentRoom, vector<bool>& visited) {
        for (int key : rooms[currentRoom])
            if (!visited[key]) {
                visited[key] = true;
                dfs(rooms, key, visited);
            }
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited (rooms.size(), false);
        visited[0] = true;
        dfs(rooms, 0, visited);
        for (bool roomVisited : visited)
            if (!roomVisited)
                return false;
        return true;
    }
};