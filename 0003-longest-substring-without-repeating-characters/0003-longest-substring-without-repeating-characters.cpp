class Solution {
public:
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