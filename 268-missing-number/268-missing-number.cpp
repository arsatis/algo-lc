class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        int ans = nums.size();
        for (int i = 0; i < nums.size(); ++i) ans ^= (nums[i] ^ i);
        return ans;
    }
};