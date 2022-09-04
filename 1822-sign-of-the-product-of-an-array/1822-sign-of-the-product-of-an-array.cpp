class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool isNeg = false;
        for (int& i : nums) {
            if (i == 0) return 0;
            if (i < 0) isNeg ^= 1;
        }
        return isNeg ? -1 : 1;
    }
};