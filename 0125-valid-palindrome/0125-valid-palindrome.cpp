class Solution {
public:
    bool isPalindrome(string& s) {
        for (int l = 0, r = s.size() - 1; l < r; ++l, --r) {
            while (isalnum(s[l]) == false && l < r) ++l;
            while (isalnum(s[r]) == false && l < r) --r;
            if (toupper(s[l]) != toupper(s[r])) return false;
        }
        return true;
    }
};
