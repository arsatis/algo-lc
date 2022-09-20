class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int peakIndexInMountainArray(vector<int>& arr) {
        for (int n = arr.size() - 1, l = 0, r = n; l <= r;) {
            int m = (l + r) >> 1;
            if (m == 0 || (arr[m - 1] < arr[m] && arr[m] < arr[m + 1]))
                l = m + 1;
            else if (m == n || (arr[m - 1] > arr[m] && arr[m] > arr[m + 1]))
                r = m - 1;
            else return m;
        }
        return -1;
    }
};