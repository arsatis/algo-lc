class Solution {
    void dfs(vector<vector<int>>& rooms, int curr, vector<bool>& visited) {
        for (int key : rooms[curr])
            if (!visited[key]) {
                visited[key] = true;
                dfs(rooms, key, visited);
            }
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited (rooms.size(), false);
        visited[0] = true;
        dfs(rooms, 0, visited);
        for (bool roomVisited : visited) if (!roomVisited) return false;
        return true;
    }
};