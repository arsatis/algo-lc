class Solution {
public:
    bool isStrobogrammatic(string& num) {
        unordered_map<char, char> comp = {
            {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
        };
        string num2(num.rbegin(), num.rend());
        for (char& c : num2)
            if (comp.find(c) != comp.end()) c = comp[c];
            else return false;
        return num == num2;
    }
};
