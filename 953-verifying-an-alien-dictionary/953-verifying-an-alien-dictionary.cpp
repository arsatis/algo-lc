class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_map<char, int> dict;
        for (int i = 0; i < order.size(); ++i) dict[order[i]] = i;
        
        vector<string> words2 = words;
        sort(words.begin(), words.end(), [&dict](auto& x, auto& y) {
            int n = max(x.size(), y.size());
            for (int i = 0; i < n; ++i) {
                if (i == x.size()) return true;
                if (i == y.size() || dict[x[i]] > dict[y[i]]) return false;
                if (dict[x[i]] < dict[y[i]]) return true;
            }
            return true;
        });
        for (int i = 0; i < words.size(); ++i)
            if (words[i] != words2[i]) return false;
        return true;
    }
};