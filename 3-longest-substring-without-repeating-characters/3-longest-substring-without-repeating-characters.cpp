#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        size_t max_len = 0;
        unordered_set<char> sc;
        while (right < s.size()) {
            if (sc.find(s[right]) == sc.end()) {
                sc.insert(s[right]);
                max_len = max(max_len, sc.size());
            } else {
                while (sc.find(s[right]) != sc.end()) {
                    sc.erase(s[left]);
                    left += 1;
                }
                sc.insert(s[right]);
            }
            right += 1;
        }
        return max_len;
    }
};