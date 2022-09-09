class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        ios_base::sync_with_stdio(0);
        
        unordered_map<char, int> dict;
        for (int i = 0; i < order.size(); ++i) dict[order[i]] = i;
        
        auto it1 = words.begin(), it2 = it1 + 1;
        while (it2 != words.end()) {
            int size = min(it1->size(), it2->size());
            for (int i = 0; i < size; ++i) {
                if (dict[(*it1)[i]] > dict[(*it2)[i]]) return false;
                if (dict[(*it1)[i]] < dict[(*it2)[i]]) break;
            }
            if (((*it1).size() > (*it2).size()) &&
                (dict[(*it1)[size-1]] == dict[(*it2)[size-1]]))
                return false;
            ++it1, ++it2;
        }
        return true;
    }
};