#include <unordered_map>

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<long, int> d;
        for (string &word : words) {
            long mask = 0;
            for (auto &c : word) {
                mask |= (1 << (c - 97));
            }
            d[mask] = max((int) word.size(), d.find(mask) == d.end() ? 0 : d[mask]);
        }
        int output = 0;
        for (auto i = d.begin(); i != d.end(); ++i) {
            for (auto j = ++d.begin(); j != d.end(); ++j) {
                if (!(i->first & j->first))
                    output = max(output, i->second * j->second);
            }
        }
        return output;
    }
};