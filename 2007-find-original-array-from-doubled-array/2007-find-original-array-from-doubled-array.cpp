class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() & 1) return {};
        
        int M = *max_element(changed.begin(), changed.end()), size = 1 + (M << 1);
        vector<int> v(size), ans;
        
        for (int& x : changed) ++v[x];
        if (v[0] & 1) return {};
        ans.resize(v[0] >> 1);
        for (int i = 1; i != size; ++i) {
            if (!v[i]) continue;
            if (v[i << 1] < v[i]) return {};
            v[i << 1] -= v[i];
            ans.resize(ans.size() + v[i], i);
        }
        return move(ans);
    }
};