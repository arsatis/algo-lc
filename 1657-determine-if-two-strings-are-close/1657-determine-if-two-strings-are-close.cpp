class Solution {
public:
    bool closeStrings(string& word1, string& word2) {
        if (word1.size() != word2.size()) return false;
        int counter1[26] = {}, counter2[26] = {};
        for (char c : word1) ++counter1[c - 'a'];
        for (char c : word2) {
            if (counter1[c - 'a'] == 0) return false;
            ++counter2[c - 'a'];
        }
        sort(counter1, counter1 + 26);
        sort(counter2, counter2 + 26);
        for (int i = 0; i < 26; ++i) if (counter1[i] != counter2[i]) return false;
        return true;
    }
};
