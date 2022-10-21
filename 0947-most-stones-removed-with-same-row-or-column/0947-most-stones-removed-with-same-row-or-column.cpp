class Solution {
    int rank[20001] = {}, parent[20002];
    int findpar(int node, int* parent) {
        if (parent[node] == node) return node;
        return parent[node] = findpar(parent[node], parent);
    }
    
    void unionset(int n1, int n2, int* parent) {
        int par1 = findpar(n1,parent), par2 = findpar(n2,parent);
        if (par1 != par2) {
            if (rank[par1] > rank[par2]) parent[par2] = par1;
            else if (rank[par2] > rank[par1]) parent[par1] = par2;
            else{
                parent[par1] = par2;
                ++rank[par2];
            }
        }
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        for (int i = 0; i < 20002; ++i) parent[i] = i;
        for (int i = 0; i < stones.size(); ++i) unionset(stones[i][0], stones[i][1] + 10001,parent);
        
        unordered_set<int> s;
        for (int i = 0; i < stones.size(); ++i) s.insert(findpar(stones[i][0], parent));
        return stones.size() - s.size(); 
    }
};