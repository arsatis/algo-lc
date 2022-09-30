class Solution {
    int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i==0&&j==0)return grid[0][0];
        if(i<0||j<0)return 1000009;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=grid[i][j]+func(i-1,j,grid,dp);
        int left=grid[i][j]+func(i,j-1,grid,dp);
        return dp[i][j]=min(left,up);
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,grid,dp);
    }
};