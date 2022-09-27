class Solution {
    vector<int> helper(vector<vector<int>>& mat,int k){
        set<pair<int,int>>st;
        int n = mat.size();
        for(int i=0;i<n;i++){
            int cnt = count(mat[i].begin(),mat[i].end(),1);
            st.insert({cnt,i});
        }
        
        vector<int>ans;
        for(auto i:st){
            if(k==0){
                break;
            }
            ans.push_back(i.second);
            k--;
        }
        
        return ans;
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        return helper(mat,k);
    }
};