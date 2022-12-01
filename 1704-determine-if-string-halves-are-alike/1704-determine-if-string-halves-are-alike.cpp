class Solution {
public:
    bool halvesAreAlike(string& s) {
        auto f = [](char c) {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int numVowels = 0, half = s.size() >> 1;
        for (int i = 0; i < half; ++i) if (f(s[i])) ++numVowels;
        for (int i = half; i < s.size(); ++i) if (f(s[i])) --numVowels;
        return numVowels == 0;
    }
};
