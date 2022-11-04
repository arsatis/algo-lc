class Solution {
    bool f(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return false;
        return true;
    }
public:
    string reverseVowels(string& s) {
        for (int l = 0, r = s.size() - 1; l < r;) {
            while (l < s.size() && f(s[l])) ++l;
            while (r >= 0 && f(s[r])) --r;
            if (l >= r) break;
            swap(s[l], s[r]);
            ++l, --r;
        }
        return s;
    }
};
