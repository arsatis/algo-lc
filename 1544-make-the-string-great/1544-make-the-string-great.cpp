class Solution {
public:
    string makeGood(string& s) {
        string output = "";
        for (char c : s) {
            if (output.empty()) output += c;
            else {
                if (c <= 'Z' && output.back() == c - 'A' + 'a') output.pop_back();
                else if (c > 'Z' && output.back() == c - 'a' + 'A') output.pop_back();
                else output += c;
            }
        }
        return output;
    }
};
