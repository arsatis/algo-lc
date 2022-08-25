class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        ios_base::sync_with_stdio(0);
        
        int chars[26] = { 0 };
        for (char& c : magazine) ++chars[c - 'a'];
        for (char& c : ransomNote) {
            if (chars[c - 'a'] == 0) return false;
            --chars[c - 'a'];
        }
        return true;
    }
};