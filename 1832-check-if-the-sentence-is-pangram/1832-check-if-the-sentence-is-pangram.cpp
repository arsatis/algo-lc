class Solution {
public:
    bool checkIfPangram(string& sentence) {
        int counter[26] = {};
        for (char c : sentence) ++counter[c - 'a'];
        for (int i : counter) if (i == 0) return false;
        return true;
    }
};