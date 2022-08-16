class Solution {
public:
    int firstUniqChar(string s) {
        int charCount[128] = {0};
        for (char& c : s) ++charCount[c];
        for (int i = 0; i < s.size(); ++i)
            if (charCount[s[i]] == 1) return i;
        return -1;
    }
};