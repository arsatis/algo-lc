class Solution {
    bool ok(vector<int> &a, int target, int d) {
        for (int lo=0, hi=a.size()-1; lo <= hi; ) {
            int mid=(lo+hi)>>1;
            if(abs(a[mid]-target) <= d) return 0;
            else if(a[mid]<target) lo=mid+1;
            else hi=mid-1;
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
        for (auto x : a) if (ok(b, x, d)) ++dist;
        return dist;
    }
};