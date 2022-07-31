class Solution {
public:
    int romanToInt(string s) {
        char prev;
        int output = 0;
        for (auto it = s.end() - 1; it != s.begin() - 1; --it) {
            if (*it == 'M') output += 1000;
            else if (*it == 'D') output += 500;
            else if (*it == 'C') {
                if (prev == 'M' || prev == 'D') output -= 100;
                else output += 100;
            }
            else if (*it == 'L') output += 50;
            else if (*it == 'X') {
                if (prev == 'C' || prev == 'L') output -= 10;
                else output += 10;
            }
            else if (*it == 'V') output += 5;
            else if (*it == 'I') {
                if (prev == 'X' || prev == 'V') output -= 1;
                else output += 1;
            }
            prev = *it;
        }
        return output;
    }
};