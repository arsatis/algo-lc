class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for (auto& point : points) {
            double dist = sqrt(pow(point.front(), 2) + pow(point.back(), 2));
            if (pq.size() < k) pq.emplace(dist, point);
            else if (dist < pq.top().first) pq.pop(), pq.emplace(dist, point);
        }
        
        vector<vector<int>> closest(k);
        for (int i = 0; i < k; ++i) {
            closest[i] = pq.top().second;
            pq.pop();
        }
        return move(closest);
    }
};