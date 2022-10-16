class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int minDifficulty(vector<int>& A, int d) {
        int n = A.size();
        if (n < d) return -1;
        vector<int> dp(n, 1000), dp2(n), stack;
        for (int j = 0; j < d; ++j) {
            stack.clear();
            for (int i = j; i < n; ++i) {
                dp2[i] = i ? dp[i - 1] + A[i] : A[i];
                while (stack.size() && A[stack.back()] <= A[i]) {
                    int j = stack.back(); stack.pop_back();
                    dp2[i] = min(dp2[i], dp2[j] - A[j] + A[i]);
                }
                if (!stack.empty()) dp2[i] = min(dp2[i], dp2[stack.back()]);
                stack.push_back(i);
            }
            swap(dp, dp2);
        }
        return dp[n - 1];
    }
};