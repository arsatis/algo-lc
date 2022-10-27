class Solution {
public:
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