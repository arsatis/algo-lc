class Solution {
    int calculateSoldierCount(vector<int>& v) {
        int l = 0, h = v.size() - 1;
        while (l <= h) {
            int mid = (h + l) >> 1;
            if (v[mid] == 0) h = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
    
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> max_heap;
        for (int i = 0; i < mat.size(); ++i) {
            max_heap.emplace(calculateSoldierCount(mat[i]), i);
            if (max_heap.size() > k) max_heap.pop();
        }
        
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = max_heap.top().second;
            max_heap.pop();
        }
        return move(ans);
    }
};