class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        long long dp[30000] = {};
        vector<int> stack;
        
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() and arr[stack.back()] > arr[i]) stack.pop_back();
            if (stack.empty()) dp[i] = (i + 1) * arr[i];
            else dp[i] = dp[stack.back()] + (i - stack.back()) * arr[i];
            stack.emplace_back(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) ans = (ans + dp[i]) % mod;
        return ans;
    }
};
