class Solution {
public:
    int partitionString(string& s) {
        int count = 1, counter[26] = {};
        for (int l = 0, r = 0; r < s.size(); ++r) {
            if (counter[s[r] - 'a']++) {
                while (l < r) --counter[s[l++] - 'a'];
                ++count;
            }
        }
        return count;
    }
};
