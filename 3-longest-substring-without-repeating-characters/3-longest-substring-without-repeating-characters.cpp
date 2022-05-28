#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vi(256, -1);
        int max_len = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (vi[s[i]] > start)
                start = vi[s[i]];
            vi[s[i]] = i;
            max_len = max(max_len, i - start);
        }
        return max_len;
    }
};