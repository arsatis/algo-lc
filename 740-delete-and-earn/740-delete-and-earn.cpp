class Solution {
    int N = 10001;
    int solve(vector<int> &nums,int i,vector<int> &dp){
        int n = nums.size();
        // if(i>=n) return 0;
        
        if(i==1) return nums[0];
        if(i==2) return max(nums[0],nums[1]);
        if(dp[i-1] != -1) return dp[i-1];
        return dp[i-1] = max((nums[i-1] + solve(nums,i-2,dp)),solve(nums,i-1,dp));
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;

        //take the total sum by each number
        vector<int> sum(n, 0);
        vector<int> dp(n, 0);

        for(auto num: nums){
            sum[num] += num;
        }

        dp[0] = 0;
        dp[1] = sum[1];
        //now apply the house robbing concept
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-2] + sum[i], dp[i-1]);
        }

        return dp[n-1];
    }
};