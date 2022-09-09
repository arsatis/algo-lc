class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dict;
        
        for (int i = 0; i < order.size(); ++i) dict[order[i]] = i;
        for (int i = 0; i < words.size() - 1; ++i) {
            int size = min(words[i].size(), words[i + 1].size());
            for (int j = 0; j < size; ++j) {
                if (dict[words[i][j]] > dict[words[i + 1][j]]) return false;
                if (dict[words[i][j]] < dict[words[i + 1][j]]) break;
            }
            if (words[i].size() > words[i + 1].size() &&
                dict[words[i][size - 1]] == dict[words[i + 1][size - 1]])
                return false;
        }
        return true;
    }
};