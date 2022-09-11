class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        sort(arr.begin(), arr.end(), [](int i, int j) {
            bitset<14> bi(i), bj(j);
            return bi.count() != bj.count() ? bi.count() < bj.count() : i < j;
        });
        return arr;
    }
};