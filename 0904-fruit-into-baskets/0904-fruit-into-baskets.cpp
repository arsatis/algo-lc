class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen = 0, num = 0, counter[fruits.size()];
        memset(counter, 0, sizeof(counter));
        for (int l = 0, r = 0; r < fruits.size(); ++r) {
            if (counter[fruits[r]] == 0) {
                if (num == 2) while (--counter[fruits[l++]] > 0);
                else ++num;
            }
            ++counter[fruits[r]];
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
