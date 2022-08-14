class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        stack<pair<int, int>> s;
        
        for (int i = 0; i < v.size(); ++i) {
            int cs = v[i][0], ce = v[i][1];
            if (s.size() == 0) s.push({cs, ce});
            else {
                int ps = s.top().first, pe = s.top().second;
                if (pe >= cs) {
                    s.pop();
                    s.push({ps, max(ce,pe)});
                }
                else s.push({cs, ce});
            }
        }
        while (s.size()) {
            res.push_back({s.top().first, s.top().second});
            s.pop();
        }
        reverse(res.begin(), res.end()); 
        return res;
    }
};