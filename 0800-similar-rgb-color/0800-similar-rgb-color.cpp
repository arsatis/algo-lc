class Solution {
    char f(char c1, char c2) {
        string s;
        s += c1, s += c2;
        int val = stoi(s, nullptr, 16), diff = 256, minChar;
        for (int i = 0; i < 16; ++i) {
            int curr = (i << 4) + i;
            if (abs(curr - val) < diff) {
                diff = abs(curr - val);
                minChar = i;
            }
        }
        return minChar + (minChar <= 9 ? '0' : 'a' - 10);
    }
public:
    string similarRGB(string& color) {
        string output = "#";
        for (uint8_t i = 1; i < color.size(); i += 2) {
            char c = f(color[i], color[i + 1]);
            output += c, output += c;
        }
        return move(output);
    }
};