class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> cindex[4];
        for (int i = 0; i < colors.size(); ++i) cindex[colors[i]].emplace_back(i);

        vector<int> res;
        res.reserve(queries.size());
        for (auto& q : queries){
            auto& v = cindex[q[1]];
            int c = q[1], i = q[0], j = lower_bound(v.begin(), v.end(), q[0]) - v.begin(), ans = 1e5;
            if (j < v.size()) ans = v[j] - i;
            if (j != 0) ans = min(ans, i - v[j - 1]);
            res.emplace_back(ans == 1e5 ? -1 : ans);
        }
        return move(res);
    }
};
