class Solution {
    int f(char& c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        if (c == 'M') return 1000;
        return 0;
    }
public:
    int romanToInt(string s)  {
        ios_base::sync_with_stdio(0);
        
        int output = 0;
        for (int i = 0; i < s.size(); ++i) {
           if (i < s.size() - 1 && f(s[i]) < f(s[i + 1])) output -= f(s[i]);
           else output += f(s[i]);
        }
        return output;
    }
};