class Solution {
public:
    int characterReplacement(string s, int k) {
        ios_base::sync_with_stdio(0);
        
        int count[26];
        fill(count, count + 26, 0);
        
        int start = 0, max_count = 0, max_length = 0;
        for (int end = 0; end < s.size(); ++end) {
            max_count = max(max_count, ++count[s[end] - 'A']);
            if (end - start + 1 - max_count > k) {
                --count[s[start] - 'A'];
                ++start;
            }
            max_length = max(max_length, end - start + 1);
        }
        return max_length;
    }
};