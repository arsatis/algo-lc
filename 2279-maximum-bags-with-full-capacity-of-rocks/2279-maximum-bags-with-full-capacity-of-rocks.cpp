class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> diff(rocks.size());
        for (int i = 0; i < rocks.size(); ++i) ++diff[i] = capacity[i] - rocks[i];
        sort(diff.begin(), diff.end());

        int i = 0;
        for (; i < diff.size(); ++i) {
            if (diff[i] <= additionalRocks) additionalRocks -= diff[i];
            else return i;
        }
        return i;
    }
};
