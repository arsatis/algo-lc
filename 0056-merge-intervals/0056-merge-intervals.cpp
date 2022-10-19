class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < intervals.size(); ++i) arr.emplace_back(intervals[i][0], intervals[i][1]);
        sort(arr.begin(),arr.end());
        stack<pair<int,int>> st;
        for(int i = 0;i<arr.size();i++) {
             if (st.empty()) st.push(arr[i]);
             else {
                 if (arr[i].first <= st.top().second) st.top().second = max(st.top().second,arr[i].second);
                 else st.push(arr[i]);
             }
         }
         vector<vector<int>> ans(st.size(), vector<int>(2));
         int i = 0;
         while (!st.empty()) {
            ans[i++] = {st.top().first, st.top().second};
            st.pop();
         }
         return ans;
    }
};