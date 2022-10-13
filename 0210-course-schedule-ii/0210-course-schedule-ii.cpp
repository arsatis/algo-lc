class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> next(numCourses), prev(numCourses);
        for (auto& prereq : prerequisites) {
            next[prereq.back()].insert(prereq.front());
            prev[prereq.front()].insert(prereq.back());
        }
        
        vector<int> order, visited(numCourses);
        order.reserve(numCourses);
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (prev[i].empty()) q.emplace(i);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto& s : prev) s.erase(curr);
            order.emplace_back(curr);
            for (int x : next[curr])
                if (!visited[x] && prev[x].empty())
                    q.emplace(x), ++visited[x];
        }
        return order.size() == numCourses ? move(order) : vector<int>();
    }
};