class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int innerIdx = 0, outerIdx = 0;
        for (char c : s) {
            if (outerIdx == words.size() || c != words[outerIdx][innerIdx++]) return false;
            if (innerIdx == words[outerIdx].size()) innerIdx = 0, ++outerIdx;
        }
        return innerIdx == 0;
    }
};