class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(0);
        
        int left = 0, right = 0, minLeft = 0, minRight = 0, count = t.size();
        int arr[64] = { 0 };
        
        for (char& c : t) ++arr[c - 'A'];
        while (right < s.size()) {
            count -= (arr[s[right] - 'A'] > 0);
            --arr[s[right] - 'A'];
            ++right;
            if (count == 0) {
                while (left < right && arr[s[left] - 'A'] < 0) {
                    ++arr[s[left] - 'A'];
                    ++left;
                }
                if (!minRight || minRight - minLeft > right - left) {
                    minLeft = left;
                    minRight = right;
                }
            }
        }
        return s.substr(minLeft, minRight - minLeft);
    }
};