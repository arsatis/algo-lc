class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int idx = -1, dist = INT_MAX;
        
        for (int i = 0; i < points.size(); ++i) {
            if (x == points[i][0] && abs(y - points[i][1]) < dist) {
                idx = i;
                dist = abs(y - points[i][1]);
            } else if (y == points[i][1] && abs(x - points[i][0]) < dist) {
                idx = i;
                dist = abs(x - points[i][0]);
            }
        }
        return idx;
    }
};