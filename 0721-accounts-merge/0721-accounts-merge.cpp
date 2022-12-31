class Solution {
    unordered_map<string, int> rep;
    vector<int> par;

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        par.resize(accounts.size());
        iota(par.begin(), par.end(), 0);
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (rep.count(accounts[i][j])) par[find(rep[accounts[i][j]])] = i;
                rep[accounts[i][j]] = i;
            }
        }

        vector<set<string>> merged(accounts.size());
        for (int i = 0; i < accounts.size(); ++i) {
            int idx = find(par[i]);
            if (merged[idx].empty()) merged[idx].insert("!");
            for (int j = 1; j < accounts[i].size(); ++j)
                merged[idx].insert(accounts[i][j]);
        }

        vector<vector<string>> output;
        for (int i = 0; i < merged.size(); ++i)
            if (!merged[i].empty()) {
                output.emplace_back(merged[i].begin(), merged[i].end());
                output[output.size() - 1][0] = accounts[i][0];
            }
        return move(output);
    }
};
