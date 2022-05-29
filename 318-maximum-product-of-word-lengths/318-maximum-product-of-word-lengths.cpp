#include <unordered_map>

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> d;
        for (string &word : words) {
            int mask = 0;
            for (auto &c : word) {
                mask |= 1 << (c - 'a');
            }
            d[mask] = max((int) word.size(), d[mask]);
        }
        int output = 0;
        for (auto i : d)
            for (auto j : d)
                if (!(i.first & j.first))
                    output = max(output, i.second * j.second);
        return output;
    }
};