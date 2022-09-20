class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0, mid, e=arr.size();
        while (s < e) {
            mid = (e + s) / 2;
            if (arr[mid] >= arr[mid + 1]) e = mid;
            else s = mid + 1;
        }
        return s;
    }
};