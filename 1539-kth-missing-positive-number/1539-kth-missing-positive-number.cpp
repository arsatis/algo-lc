class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size();
        while (l < r) {
            int m = (l + r) >> 1;
            if (arr[m] - 1 - m < k) l = m + 1;
            else r = m;
        }
        return l + k;
    }
};