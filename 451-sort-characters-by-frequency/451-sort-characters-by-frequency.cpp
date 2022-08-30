class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        for (char c : s) ++counts[c];
        
        int n = counts.size(), i = 0;
        string ss = "";
        vector<pair<int, char>> arr(n);
        for (auto& p : counts) {
            arr[i] = { p.second, p.first };
            ++i;
        }
        sort(arr.begin(), arr.end(), [](auto& x, auto& y) {
            return x.first > y.first;
        });
        for (i = 0; i < n; ++i)
            for (int j = 0; j < arr[i].first; ++j)
                ss += arr[i].second;
        return ss;
    }
};