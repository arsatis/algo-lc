class Solution {
    vector<vector<int>> combs;
    void f(vector<int>& candidates, vector<int>& comb, int k, int idx) {
        for (int i = idx + 1; i < candidates.size(); ++i) {
            // if c[i] == c[i - 1] and c[i - 1] wasn't added, skip this idx
            if (i > idx + 1 && candidates[i] == candidates[i - 1]) continue;

            // backtracking
            int k2 = k - candidates[i];
            if (k2 < 0) return;
            comb.emplace_back(candidates[i]);
            if (k2 == 0) combs.emplace_back(comb);
            else f(candidates, comb, k2, i);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        f(candidates, comb, target, -1);
        return move(combs);
    }
};
