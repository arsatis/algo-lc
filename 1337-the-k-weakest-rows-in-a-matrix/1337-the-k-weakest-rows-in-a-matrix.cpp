class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> score;
        vector<int> ans;
        for(auto i:mat){
            int s=0;
            for(auto j:i){
                if(j) ++s;
            }
            score.push_back(s);
        }
        vector<bool> used(score.size(),0);
        for(int i=0;i<k;++i){
            int min=1000;
            int min_index=0;
            for(int j=0;j<score.size();++j){
                if(score[j]<min and (!used[j])) {min=score[j]; min_index=j;}
            }
            used[min_index]=1;
            ans.push_back(min_index);
        }
        return ans;
    }
};