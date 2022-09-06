class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0, n = arr.size();
        for (int i = 0; i < n; ++i)
            res += (((i + 1) * (n - i) + 1) >> 1) * arr[i];
        return res;
    }
};