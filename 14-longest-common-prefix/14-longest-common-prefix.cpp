class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios_base::sync_with_stdio(0);

        string::size_type idx = 0;
        while (idx < strs[0].size()) {
            for (int i = 1; i < strs.size(); ++i)
                if (idx >= strs[i].size() || strs[i][idx] != strs[0][idx])
                    return strs[0].substr(0, idx);
            ++idx;
        }
        return strs[0].substr(0, idx);
    }
};