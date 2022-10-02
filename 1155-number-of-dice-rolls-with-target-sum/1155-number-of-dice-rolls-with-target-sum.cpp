class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int numRollsToTarget(int n, int l, int target) {
        if(target<n || target>n*l) return 0;
        int mod=1000000007;
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int total=0;
            for(int j=max(0, target-l);j<=target;j++) total=(total+dp[j])%mod;
            for(int j=target;j>=0;j--){
                total=(total-dp[j]+mod)%mod;
                dp[j]=total;
                if(j-l-1>=0) total=(total+dp[j-l-1])%mod;
            }
        }
        return dp[target];
    }
};

// Solution 1: top-down dp
//     int mod = 1e9 + 7, k;
//     vector<vector<int>> memo;
    
//     int dp(int n, int rem) {
//         if (n == 0) return rem == 0;
//         if (memo[n][rem] != -1) return memo[n][rem];
//         else {
//             int numWays = 0;
//             for (int i = 1; i <= min(k, rem); ++i)
//                 numWays = (numWays + dp(n - 1, rem - i)) % mod;
//             return memo[n][rem] = numWays;
//         }
//     }
    
//     int numRollsToTarget(int n, int k, int target) {
//         this->k = k;
//         memo.resize(n + 1, vector<int>(target + 1, -1));
//         return dp(n, target);
//     }