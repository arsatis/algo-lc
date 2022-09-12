class Solution {
public:
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        int i = 0, j = 0;
        for (int x : nums) {
            int tmp = i;
            i = max(j + x, i);
            j = tmp;
        }
        return i;
    }
};