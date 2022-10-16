class Solution {
public:
    string minWindow(string& s, string& t) {
        int left = 0, right = 0, minLeft = 0, minRight = 100001, count = t.size();
        int counter[64] = {};
        
        for (char c : t) ++counter[c - 'A'];
        while (right < s.size()) {
            count -= (counter[s[right++] - 'A']-- > 0);
            if (count == 0) {
                while (counter[s[left] - 'A'] < 0) ++counter[s[left++] - 'A'];
                if (minRight - minLeft > right - left) minLeft = left, minRight = right;
            }
        }
        return minRight == 100001 ? "" : s.substr(minLeft, minRight - minLeft);
    }
};