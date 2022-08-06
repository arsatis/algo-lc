class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        while (idx < strs[0].size()) {
            char c = strs[0][idx];
            for (int i = 1; i < strs.size(); ++i) {
                string s = strs[i];
                if (idx >= s.size() || s[idx] != c)
                    return s.substr(0, idx);
            }
            ++idx;
        }
        return strs[0].substr(0, idx);
    }
};