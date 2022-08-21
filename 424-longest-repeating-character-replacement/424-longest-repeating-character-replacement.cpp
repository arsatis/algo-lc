class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charCounts;
        int curr = 0, maxCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++charCounts[s[i]];
            maxCount = max(maxCount, charCounts[s[i]]);
            while (i - curr + 1 - maxCount > k) {
                --charCounts[s[curr]];
                ++curr;
            }
        }
        return s.size() - curr;
    }
};