class Solution {
public:
    string freqAlphabets(string s) {
        string output = "";
        for (auto it = s.begin(); it < s.end();) {
            auto it2 = find(it, s.end(), '#');
            while (it2 - it > 2) output += *(it++) + 48;
            if (it2 != s.end()) output += '`' + (*(it++) - '0') * 10 + (*it - '0');
            else while (it < s.end()) output += *(it++) + 48;
            it = it2 + 1;
        }
        return output;
    }
};