class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int lengthOfLongestSubstring(string& s) {
        int maxLen = 0, counter[128] = {};
        for (int left = 0, right = 0; right < s.size(); ++right) {
            while (counter[s[right]]) --counter[s[left++]];
            ++counter[s[right]];
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};