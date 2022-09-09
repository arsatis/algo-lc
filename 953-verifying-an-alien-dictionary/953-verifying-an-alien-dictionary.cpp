class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        std::unordered_map<char, int> letter_map;
        auto it = order.begin();
        while (it != order.end())
            letter_map[*it] = std::distance(order.begin(), it++);
        
        auto it1 = words.begin(), it2 = it1 + 1;
        while (it2 != words.end()) {
            int size = (*it1).size() > (*it2).size() ? (*it2).size() : (*it1).size();
            for (int i = 0; i < size; ++i) {
                if (letter_map[(*it1)[i]] != letter_map[(*it2)[i]]) {
                    if (letter_map[(*it1)[i]] > letter_map[(*it2)[i]]) return false;
                    break;
                }
            }
            if (((*it1).size() > (*it2).size()) &&
                (letter_map[(*it1)[size-1]] == letter_map[(*it2)[size-1]]))
                return false;
            ++it1, ++it2;
        }
        return true;
    }
};