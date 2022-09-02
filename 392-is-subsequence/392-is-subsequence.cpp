class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPtr = 0, tPtr = -1;
        while (sPtr < s.size()) {
            while (1) {
                if (++tPtr > t.size()) return false;
                if (s[sPtr] == t[tPtr]) break;
            }
            ++sPtr;
        }
        return true;
    }
};