class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26];
        fill(count, count + 26, 0);
        
        int start = 0, max_count = 0;
        for (int end = 0; end < s.size(); ++end) {
            max_count = max(max_count, ++count[s[end] - 'A']);
            if (end - start + 1 - max_count > k) {
                --count[s[start] - 'A'];
                ++start;
            }
        }
        return s.size() - start;
    }
};