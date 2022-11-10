class Solution {
public:
    string removeDuplicates(string& s) {
        string output = "";
        for (char c : s) {
            if (output.empty() || output.back() != c) output += c;
            else output.pop_back();
        }
        return move(output);
    }
};
