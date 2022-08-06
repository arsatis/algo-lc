class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios_base::sync_with_stdio(false);

        int idx = 0;
        string s = "";
        while (idx < strs[0].size()) {
            for (int i = 1; i < strs.size(); ++i)
                if (idx >= strs[i].size() || strs[i][idx] != strs[0][idx])
                    return s;
            s.push_back(strs[0][idx]);
            ++idx;
        }
        return s;
    }
};