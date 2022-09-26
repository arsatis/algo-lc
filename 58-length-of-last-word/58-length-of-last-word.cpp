class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int lengthOfLastWord(string s) {
        int len = 0, tail = s.size() - 1;
        while (tail >= 0 && s[tail] == ' ') --tail;
        while (tail >= 0 && s[tail] != ' ') ++len, --tail;
        return len;
    }
};