class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int, int>> st;
        vector<int> days(temperatures.size());
        st.reserve(days.size());
        for (int i = days.size() - 1; i >= 0; --i) {
            while (!st.empty() && temperatures[i] >= st.back().first) st.pop_back();
            if (!st.empty()) days[i] = st.back().second - i;
            st.emplace_back(temperatures[i], i);
        }
        return move(days);
    }
};