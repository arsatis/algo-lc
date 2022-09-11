class Solution {
    void f(int n, int k, vector<vector<int>>& combs, vector<int>& comb) {
        if (comb.size() == k) combs.push_back(comb);
        else {
            int rem = k - comb.size() - 1;
            for (int i = comb.empty() ? 1 : comb.back() + 1; i + rem <= n; ++i) {
                comb.emplace_back(i);
                f(n, k, combs, comb);
                comb.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<vector<int>> combs;
        vector<int> comb;
        comb.reserve(k);
        f(n, k, combs, comb);
        return move(combs);
    }
};