class Solution {
    bool f(vector<int>& a, int target, int d) {
        for (int l = 0, r = a.size() - 1; l <= r;) {
            int m = (l + r) >> 1;
            if (abs(a[m] - target) <= d) return 0;
            else if (a[m] < target) l = m + 1;
            else r = m - 1;
        }
        return 1;
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        sort(b.begin(), b.end());
        int dist = 0;
        for (auto x : a) if (f(b, x, d)) ++dist;
        return dist;
    }
};