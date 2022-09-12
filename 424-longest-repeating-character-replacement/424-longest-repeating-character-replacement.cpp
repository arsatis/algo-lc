class Solution {
public:
    int characterReplacement(string s, int k) {
        ios_base::sync_with_stdio(0);
        
        int count[26] = { 0 };
        int maxCount = 0, maxLength = 0;
        
        for (int start = 0, end = 0; end < s.size(); ++end) {
            maxCount = max(maxCount, ++count[s[end] - 'A']);
            if (end - start + 1 - maxCount > k) --count[s[start++] - 'A'];
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};