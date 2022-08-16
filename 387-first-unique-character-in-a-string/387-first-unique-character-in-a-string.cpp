class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_map<int, int> charCount;
        for (auto& c : s) ++charCount[c];
        for (int i = 0; i < s.size(); ++i)
            if (charCount[s[i]] == 1) return i;
        return -1;
    }
};