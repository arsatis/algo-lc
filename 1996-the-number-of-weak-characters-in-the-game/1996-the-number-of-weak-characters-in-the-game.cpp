class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int count = 0, currMax = INT_MIN;
        sort(properties.begin(), properties.end(), [](auto& x, auto& y) {
            return x.back() == y.back() ? x.front() > y.front() : x.back() < y.back();
        });
        for (int i = properties.size() - 1; i >= 0; --i) {
            if (properties[i].front() < currMax) ++count;
            currMax = max(currMax, properties[i].front());
        }
        return count;
    }
};