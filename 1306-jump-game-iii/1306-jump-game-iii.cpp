class Solution {
public:
    bool f(int i, vector<int>& arr, vector<int>& vis){
        if (i >= arr.size() || i < 0) return false;
        if (arr[i] == 0) return true;
        if (vis[i]) return false;
        
        vis[i] = true;
        if (f(i + arr[i], arr, vis)) return true;
        if (f(i - arr[i], arr, vis)) return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        return f(start, arr, vis);
    }
};