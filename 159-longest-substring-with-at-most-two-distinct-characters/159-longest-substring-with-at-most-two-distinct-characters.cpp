class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int maxLen = 0, counter[64] = { 0 };
        for (int l = 0, r = 0, currChars = 0; r < s.size(); ++r) {
            if (counter[s[r] - 'A'] == 0) {
                while (currChars == 2) if (--counter[s[l++] - 'A'] == 0) --currChars;
                ++currChars;
            }
            ++counter[s[r] - 'A'];
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};