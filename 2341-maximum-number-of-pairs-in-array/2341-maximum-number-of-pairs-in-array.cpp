class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int pairs = 0, leftovers = 0, counts[101] = { 0 };
        for (int& i : nums) {
            if (!counts[i]) {
                ++counts[i];
                ++leftovers;
            } else {
                --counts[i];
                ++pairs;
                --leftovers;
            }
        }
        return { pairs, leftovers };
    }
};