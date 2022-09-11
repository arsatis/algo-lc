class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int i, int j) {
            bitset<14> bi(i), bj(j);
            return bi.count() != bj.count() ? bi.count() < bj.count() : i < j;
        });
        return arr;
    }
};