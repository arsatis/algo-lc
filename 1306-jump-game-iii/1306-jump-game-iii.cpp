class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    bool canReach(vector<int>& arr, int start) {
        if (start < 0 || start >= arr.size() || arr[start] < 0) return false;
        arr[start] = -arr[start];
        return !arr[start] || canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }
};