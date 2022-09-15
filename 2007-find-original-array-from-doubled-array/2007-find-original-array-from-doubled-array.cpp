class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) return {};
        
        map<int, int> elements;
        vector<int> original;
        original.reserve(changed.size() >> 1);
        
        for (int i : changed) ++elements[i];
        for (auto& p : elements) {
            while (elements[p.first] > 0) {
                --elements[p.first];
                if (elements[p.first << 1]-- <= 0) return {};
                else original.emplace_back(p.first);
            }
        }
        return move(original);
    }
};