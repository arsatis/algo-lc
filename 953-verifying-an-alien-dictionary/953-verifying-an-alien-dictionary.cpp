class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int dict[26] = { 0 };
        
        for (int i = 0; i < order.size(); ++i) dict[order[i] - 'a'] = i;
        for (int i = 0; i < words.size() - 1; ++i) {
            int size = min(words[i].size(), words[i + 1].size());
            for (int j = 0; j < size; ++j) {
                if (dict[words[i][j] - 'a'] > dict[words[i + 1][j] - 'a'])
                    return false;
                if (dict[words[i][j] - 'a'] < dict[words[i + 1][j] - 'a'])
                    break;
            }
            if (words[i].size() > words[i + 1].size() &&
                dict[words[i][size - 1] - 'a'] == dict[words[i + 1][size - 1] - 'a'])
                return false;
        }
        return true;
    }
};