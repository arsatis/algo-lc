class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, maxDist = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) ++i;
            else {
                if (j - i > maxDist) maxDist = j - i;
                ++j;
            }
        }
        return maxDist;
    }
};