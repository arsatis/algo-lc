class Solution {
public:
    int calculateTime(string& keyboard, string& word) {
        int charToIdx[26] = {};
        for (int i = 0; i < 26; ++i) charToIdx[keyboard[i] - 'a'] = i;

        int time = charToIdx[word[0] - 'a'];
        for (int i = 1; i < word.size(); ++i)
            time += abs(charToIdx[word[i] - 'a'] - charToIdx[word[i - 1] - 'a']);
        return time;
    }
};
