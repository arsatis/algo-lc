class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int findLonelyPixel(vector<vector<char>>& picture) {
        const auto& n{int(size(picture))};
        if(!n)return 0;
        const auto& m{int(size(picture.front()))};
        if(!m)return 0;
        int r[n],c[m];
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(picture[i][j]=='B')++r[i],++c[j];
            }
        }
        int ret{};
        for(int i{};i<n;++i){
            for(int j{};j<m;++j){
                if(picture[i][j]=='B')ret+=(r[i]==1) and (c[j]==1);
            }
        }
        return ret;
    }
};