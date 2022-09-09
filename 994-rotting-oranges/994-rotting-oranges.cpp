class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        int time=0;
        int fresh=0;
        queue<pair<int,int>> rotten;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    rotten.push(make_pair(i,j));
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        vector<pair<int,int>> v={{1,0},{-1,0},{0,-1},{0,1}};
        while( fresh!=0 && !rotten.empty()){
            int size=rotten.size();
            for(int i=0;i<size;i++){
                int curx=rotten.front().first;
                int cury=rotten.front().second;
                rotten.pop();
                for(auto a : v){
                    int nx=curx+a.first;
                    int ny=cury+a.second;
                    if((nx>=0 && nx<m) && (ny>=0 && ny<n) && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        rotten.push({nx,ny});
                        fresh--;
                    }
                }
            }
            time++;
        }
        if(fresh!=0) return -1;
        return time;
    }
};