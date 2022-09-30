class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        int n=buildings.size();
        vector<pair<int,int>> v;
        vector<vector<int>> ans;
        multiset<int,greater<int>> m;
        
        for(int i=0;i<n;i++){
            int s=buildings[i][0];
            int e=buildings[i][1];
            int h=buildings[i][2];
            v.push_back({s,-h});
            v.push_back({e,h});
        }
        
        sort(v.begin(),v.end());
        int cur=0;
        m.insert(0);
        
        for(int i=0;i<v.size();i++){
            int x=v[i].first;
            int h=v[i].second;
            
            // if h is negative its a starting point.
            if(h<0)m.insert(abs(h));
            // else its a ending point.
            else {
                m.erase(m.find(h));
            }
            int top=*m.begin();
            if(cur!=top){
                ans.push_back({x,top});
                cur=top;
            }
        }
        return ans;
    }
};