class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int maxAtk = 0;
        for (auto& p : properties) maxAtk = max(p[0], maxAtk);
        
        vector<int> maxDef(maxAtk + 2);
        for (auto& p : properties)
            maxDef[p.front()] = max(maxDef[p.front()], p.back());
        for (int i = maxAtk - 1; i >= 0; --i)
            maxDef[i] = max(maxDef[i], maxDef[i+1]);
        
        int weak = 0;
        for (auto & p : properties)
            if (p.back() < maxDef[p.front() + 1]) ++weak;
        return weak;
    }
};