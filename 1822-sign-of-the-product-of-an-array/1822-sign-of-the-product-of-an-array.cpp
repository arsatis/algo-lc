class Solution {
public:
    int arraySign(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        bool isNeg = false;
        for (int i : nums) {
            if (i == 0) return 0;
            if (i < 0) isNeg ^= true;
        }
        return isNeg ? -1 : 1;
    }
};