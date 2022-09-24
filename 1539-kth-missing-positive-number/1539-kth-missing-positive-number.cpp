class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int findKthPositive(vector<int>& arr, int k) {
        int j = 1, i = 0, l = 0;
        while (k > 0 && i < arr.size()) {
            if (arr[i] != j) --k;
            else ++i;
            if (k == 0) return j;
            ++j;
        }
        return j + k - 1;
    }
};