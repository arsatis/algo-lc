class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        char prev;
        bool b = true;
        while (1) {
            if (idx >= strs[0].size()) break;
            prev = strs[0][idx];
            for (int i = 1; i < strs.size(); ++i) {
                if (idx >= strs[i].size() || strs[i][idx] != prev) {
                    b = false;
                    break;
                }
            }
            if (!b) break;
            ++idx;
        }
        return strs[0].substr(0, idx);
    }
};