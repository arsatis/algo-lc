class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        ios_base::sync_with_stdio(0);
        
        if (s.size() < p.size()) return {};
        int chars[26] = { 0 };
        vector<int> indices;
        
        for (char c : p) ++chars[c - 'a'];
        for (int i = 0, missing = p.size(); i <= s.size() - p.size(); ++i) {
            if (i == 0) for (int j = 0; j < p.size(); ++j) {
                if (chars[s[j] - 'a']-- > 0) --missing;
            } else {
                if (chars[s[i - 1] - 'a']++ >= 0) ++missing;
                if (chars[s[i + p.size() - 1] - 'a']-- > 0) --missing;
            }
            if (!missing) indices.emplace_back(i);
        }
        return move(indices);
    }
};