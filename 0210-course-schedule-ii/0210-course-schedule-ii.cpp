class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> numPrere(numCourses), result;
        queue<int> q;
        
        for (auto& pre: prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            ++numPrere[pre[0]];
        }
        for (int i = 0; i < numCourses; ++i) if (numPrere[i] == 0) q.push(i);
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            result.push_back(cur);
            for (int child : graph[cur]) if (--numPrere[child] == 0) q.push(child);
        }
        if (result.size() == numCourses) return move(result);
        else return {};
    }
};