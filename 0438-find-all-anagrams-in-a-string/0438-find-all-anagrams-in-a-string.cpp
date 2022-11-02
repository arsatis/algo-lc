class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> findAnagrams(string& s, string& p) {
        if (p.size() > s.size()) return {};
        int missing = p.size(), counter[26] = {};
        for (char c : p) ++counter[c - 'a'];
        
        vector<int> output;
        output.reserve(s.size() - p.size() + 1);
        for (int i = 0; i < s.size(); ++i) {
            if (i >= p.size() && ++counter[s[i - p.size()] - 'a']) ++missing;
            if (counter[s[i] - 'a']--) --missing;
            if (missing == 0) output.emplace_back(i - p.size() + 1);
        }
        return move(output);
    }
};