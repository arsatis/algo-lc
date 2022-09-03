class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<int> output;
        int overlap[1001] = { 0 };
        
        for (int& i : nums1) ++overlap[i];
        for (int& i : nums2) {
            if (overlap[i]) {
                output.push_back(i);
                --overlap[i];
            }
        }
        return output;
    }
};