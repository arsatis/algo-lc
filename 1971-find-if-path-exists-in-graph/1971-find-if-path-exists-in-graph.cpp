class Solution {
    int find(vector<int> &ds, int i) {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> ds(n, -1);
        for (auto &e : edges) {
            int p1 = find(ds, e[0]), p2 = find(ds, e[1]);
            if (p1 != p2) ds[p1] = p2;
        }
        return find(ds, source) == find(ds, destination);
    }
};
