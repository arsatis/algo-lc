class Solution {
    vector<vector<int>> combis;
    vector<int> combi;
    void f(vector<int>& candidates, int rem, int idx) {
        combi.emplace_back(candidates[idx]);
        if (rem == 0) combis.emplace_back(combi);
        else for (int i = idx; i < candidates.size(); ++i)
            if (rem - candidates[i] >= 0) f(candidates, rem - candidates[i], i);
        combi.pop_back();
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combi.reserve(candidates.size());
        for (int i = 0; i < candidates.size(); ++i) f(candidates, target - candidates[i], i);
        return move(combis);
    }
};