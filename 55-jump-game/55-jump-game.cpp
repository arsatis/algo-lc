class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        int i = 0;
        for (int reach = 0; i < nums.size() && i <= reach; ++i) reach = max(i + nums[i], reach);
        return i == nums.size();
    }
};