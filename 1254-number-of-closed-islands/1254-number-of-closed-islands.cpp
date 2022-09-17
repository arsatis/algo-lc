class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        
        for(int i = 0;i<n;i++){
            
            if(grid[i][0] == 0)
                dfs(i,0,grid,n,m);
            if(grid[i][m-1] == 0)
                dfs(i,m-1,grid,n,m);
        }
        for(int i = 0;i<m;i++){
            if(grid[0][i] == 0)
                dfs(0,i,grid,n,m);
            if(grid[n-1][i] == 0)
                dfs(n-1,i,grid,n,m);
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs1(i,j,grid,n,m);
                }
            }
        }
        return ans;
    }
    
    void dfs1(int i,int j,vector<vector<int>> &grid,int n,int m){
        grid[i][j] = 1;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        
        for(int l = 0;l<4;l++){
            int ni = i + dx[l];
            int nj = j + dy[l];
            if(ni>0 and nj>0 and ni<n and nj< m and grid[ni][nj] == 0)
                dfs(ni,nj,grid,n,m);
        }
    }
    
    void dfs(int i,int j,vector<vector<int>> &grid,int n,int m){
        //if(i<0 or j<0 or i>=n or j>= m) return;
        grid[i][j] = 1;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        
        for(int l = 0;l<4;l++){
            int ni = i + dx[l];
            int nj = j + dy[l];
            if(ni>0 and nj>0 and ni<n and nj< m and grid[ni][nj] == 0)
                dfs(ni,nj,grid,n,m);
        }
    }
};