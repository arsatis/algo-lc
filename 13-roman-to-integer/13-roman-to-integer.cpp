class Solution {
public:
    int romanToInt(string s) {
        char prev;
        int output = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == 'M') output += 1000;
            else if (s[i] == 'D') output += 500;
            else if (s[i] == 'C') {
                if (prev == 'M' || prev == 'D') output -= 100;
                else output += 100;
            }
            else if (s[i] == 'L') output += 50;
            else if (s[i] == 'X') {
                if (prev == 'C' || prev == 'L') output -= 10;
                else output += 10;
            }
            else if (s[i] == 'V') output += 5;
            else {
                if (prev == 'X' || prev == 'V') output -= 1;
                else output += 1;
            }
            prev = s[i];
        }
        return output;
    }
};