class Solution {
    vector<int> rep; 

    int find(int n) {
        if (rep[n] == n) return n;
        return rep[n] = find(rep[n]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        rep.resize(edges.size() + 1);
        for (int i = 0; i < edges.size(); ++i) rep[i] = i;
        for (auto& e : edges) {
            int set1 = find(e[0]), set2 = find(e[1]);
            if (set1 == set2) return e;
            if (set1 < set2) rep[set2] = set1;
            else rep[set1] = set2;
        }
        return {};
    }
};
