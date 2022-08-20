class Solution {
public:
    int minSetSize(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = arr.size() >> 1, sum = 0, count;
        int counts[100001] = { 0 };
        
        for (int& val : arr) ++counts[val];
        sort(counts, counts + 100001, [](auto& x, auto& y) { return x > y; });
        for (count = 0; count < 100001; ++count) {
            sum += counts[count];
            if (sum >= n) break;
        }
        return count + 1;
    }
};