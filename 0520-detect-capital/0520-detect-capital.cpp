class Solution {
public:
    bool detectCapitalUse(string& word) {
        if (word.size() == 1) return true;
        bool isAllCaps = isupper(word[1]);
        if (isAllCaps && islower(word[0])) return false;
        for (int i = 1; i < word.size(); ++i)
            if ((isAllCaps && islower(word[i])) || (!isAllCaps && isupper(word[i])))
                return false;
        return true;
    }
};
