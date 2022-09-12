class Solution {
public:
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        int i = 0, j = 0;
        for (int x : nums) {
            int tmp = j;
            j = max(i + x, j);
            i = tmp;
        }
        return j;
    }
};