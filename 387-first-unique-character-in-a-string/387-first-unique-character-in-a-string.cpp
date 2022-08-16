class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> charCount;
        for (auto& c : s) ++charCount[c];
        for (int i = 0; i < s.size(); ++i)
            if (charCount[s[i]] == 1) return i;
        return -1;
    }
};