class Solution {
    int f(int mask, vector<string>& arr, int i = 0) {
        if (i >= arr.size())
            return 0;
        int tmp = mask;
        for (auto& c : arr[i]) {
            if ((mask >> (c - 'a') & 1)) 
                return f(tmp, arr, i + 1);
            mask |= 1 << (c - 'a');
        }
        return max(f(tmp, arr, i + 1), (int) (f(mask, arr, i + 1) + arr[i].size()));
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int maxLength(vector<string>& arr) {
        return f(0, arr);
    }
};